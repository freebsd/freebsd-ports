# New ports collection makefile for:	mozilla-firebird
# Date created:			May 31, 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	firebird
PORTVERSION=	0.6.1
CATEGORIES=	www
#MASTER_SITES=	${MASTER_SITE_MOZILLA}
#MASTER_SITE_SUBDIR=	firebird/releases/${PORTVERSION}
MASTER_SITES=	http://pryan.org/firebird/pryan/
PKGNAMEPREFIX=	mozilla-
#DISTNAME=	MozillaFirebird-source-${PORTVERSION}
DISTNAME=	MozillaFirebird-${PORTVERSION}-source-pryan

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mozilla Firebird is the next generation browser from the mozilla.org project

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		freetype.9:${PORTSDIR}/print/freetype2 \
		iconv.3:${PORTSDIR}/converters/libiconv \
		nspr4.1:${PORTSDIR}/devel/nspr
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		freetype-config:${PORTSDIR}/print/freetype2

USE_X_PREFIX=	yes

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=	default

.if defined(WITH_GTK2)
USE_GNOME=	gtk20 libidl
PKGNAMESUFFIX=	-gtk2
.else
USE_GNOME=	gtk12 orbit
.endif

NO_MTREE=		yes
WRKSRC=			${WRKDIR}/mozilla
LOCAL_SUBDIR=		lib/${PORTNAME}
LOCAL_PREFIX=		${PREFIX}/${LOCAL_SUBDIR}
JREDIR=			${LOCALBASE}/jdk1.3.1/jre
PLUGINSDIR=		${PREFIX}/lib/browser_plugins

.include <bsd.port.pre.mk>

#.if ${PERL_LEVEL} < 500601
#.undef NO_IGNORE
#BROKEN=	Mozilla Firebird only supports the ports versions of Perl.
#BROKEN+=If you have installed a Perl port, and are getting this message,
#BROKEN+=please make sure you have given the command \'use.perl port\'.
#.endif # ${PERL_LEVEL} < 500601

SORT?=/usr/bin/sort

.if defined(WITH_DEBUG)
WITH_LOGGING=		yes
CONFIGURE_ENV+=		WITH_DEBUG=yes
.endif # defined(WITH_DEBUG)

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=		-O2
.endif # defined(WITH_OPTIMIZED_CFLAGS)

.if defined(WITH_LOGGING)
CONFIGURE_ENV+=	WITH_LOGGING=yes
.endif # defined(WITH_LOGGING)

.if defined(WITHOUT_XFT)
CONFIGURE_ENV+=	WITHOUT_XFT=yes
.else
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/Xft
.endif # !defined(WITHOUT_XFT)

.if defined(WITH_GTK2)
CONFIGURE_ENV+=	WITH_GTK2=yes
.endif # defined(WITH_GTK2)

CPPFLAGS+=		-I${X11BASE}/include
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		-L${X11BASE}/lib
LIBS+=			${PTHREAD_LIBS}

EXTRA_SCRIPTS=		firebird.rb

pre-extract::
	@${ECHO_MSG}
	@${ECHO_MSG} "Extracting source (this takes a while) ..."
	@${ECHO_MSG}

post-extract::
	@${SED} -e 's|@CPPFLAGS@|${CPPFLAGS}|'		\
		-e 's|@CFLAGS@|${CFLAGS}|'		\
		-e 's|@LDFLAGS@|${LDFLAGS}|'		\
		-e 's|@LIBS@|${LIBS}|'			\
		-e 's|@X11BASE@|${X11BASE}|'		\
		-e 's|@LOCALBASE@|${LOCALBASE}|'	\
		-e 's|@PREFIX@|${LOCAL_PREFIX}|'	\
		-e 's|@PERL@|${PERL5}|'			\
		<${FILESDIR}/mozconfig.in >${WRKSRC}/.mozconfig

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/build/unix/run-mozilla.sh

pre-install:
	${RM} -fr ${LOCAL_PREFIX}
	-${MKDIR} ${PLUGINSDIR}

install-extra:
.for i in ${EXTRA_SCRIPTS}
	${INSTALL_SCRIPT} ${FILESDIR}/${i} ${PREFIX}/bin
.endfor # i in ${EXTRA_SCRIPTS}

link-bins:
	${RM} -f ${PREFIX}/bin/firebird
	${LN} -s ${LOCAL_PREFIX}/bin/MozillaFirebird \
		${PREFIX}/bin/firebird
	${RM} -f ${PREFIX}/bin/MozillaFirebird
	${LN} -s ${LOCAL_PREFIX}/bin/MozillaFirebird \
		${PREFIX}/bin/MozillaFirebird
	${RM} -f ${PREFIX}/bin/firebird-config
	${LN} -s ${LOCAL_PREFIX}/bin/mozilla-config \
		${PREFIX}/bin/firebird-config

link-java:
	-${RM} -f ${PLUGINSDIR}/libjavaplugin_oji.so
	-${LN} -sf \
	  ${JREDIR}/plugin/${ARCH}/ns600/libjavaplugin_oji.so \
	  ${PLUGINSDIR}/libjavaplugin_oji.so

cleanup-install:
	${RM} -fr ${LOCAL_PREFIX}/share/idl
	${RM} -fr ${LOCAL_PREFIX}/include

cons-plist:
	-${RM} -f ${PLIST}
	${TOUCH} ${PLIST}
	${ECHO_CMD} bin/firebird >>${PLIST}
	${ECHO_CMD} bin/MozillaFirebird >>${PLIST}
	${ECHO_CMD} bin/firebird-config >>${PLIST}
.for i in ${EXTRA_SCRIPTS}
	${ECHO_CMD} bin/${i} >>${PLIST}
.endfor # i in ${EXTRA_SCRIPTS}
	cd ${PREFIX}; \
	${FIND} ${LOCAL_SUBDIR} ! -type d | ${SORT} >>${PLIST}; \
	${FIND} ${LOCAL_SUBDIR} -type d -empty | ${SORT} \
	  | ${SED} -e "s:^:@exec ${MKDIR} %D/:" -e "s:$$: || true:" \
	  >> ${PLIST}; \
	${FIND} ${LOCAL_SUBDIR} -type d -empty | ${SORT} -r \
	  | ${SED} -e "s:^:@unexec ${RMDIR} %D/:" -e "s:$$: || true:" \
	  >> ${PLIST}; \
	${FIND} ${LOCAL_SUBDIR} -type d ! -empty | ${SORT} -r \
		| ${SED} -e "s:^:@dirrm :" >> ${PLIST}

.PHONY: install-extra link-bins link-java cleanup-install cons-plist

.include <bsd.port.post.mk>

# <alane>
# Under normal circumstances, you should not put anything after
# the above line. However, this is the only way I can state the
# dependency without trashing the actual code of the generate-plist
# target. This is a limitation of the make(1) program itself.
# </alane>
generate-plist: install-extra link-bins link-java cleanup-install

#EOF
