# ex:ts=8
#
# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		phoenix
PORTVERSION=		0.4
PORTREVISION=		9
CATEGORIES=		www # pita
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor

MAINTAINER=		phoenix@freebsd.org # alane@fbsd and trevor@fbsd

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		freetype.9:${PORTSDIR}/print/freetype2 \
		IDL.2:${PORTSDIR}/devel/ORBit \
		Xft2.2:${PORTSDIR}/x11-fonts/Xft \
		iconv.3:${PORTSDIR}/converters/libiconv

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		freetype-config:${PORTSDIR}/print/freetype2

USE_X_PREFIX=		yes

USE_BZIP2=		yes
USE_GMAKE=		yes
USE_PERL5=		yes
USE_REINPLACE=		yes
HAS_CONFIGURE=		yes

USE_GNOMENG=		yes
USE_GNOME=		gtk12 orbit

CPPFLAGS+=		-I${X11BASE}/include
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		-L${X11BASE}/lib
LIBS+=			${PTHREAD_LIBS}

NO_MTREE=		yes
WRKSRC=			${WRKDIR}/mozilla
LOCAL_SUBDIR=		lib/${PORTNAME}
LOCAL_PREFIX=		${PREFIX}/${LOCAL_SUBDIR}
JREDIR=			${LOCALBASE}/jdk1.3.1/jre
PLUGINSDIR=		${LOCAL_PREFIX}/lib/mozilla-1.2b/plugins/

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
.undef NO_IGNORE
BROKEN=	"Phoenix only supports the ports versions of Perl."
BROKEN+="If you have installed a Perl port, and are getting this message,"
BROKEN+="please make sure you have issued the command 'use.perl port'"
.endif # ${PERL_LEVEL} < 500601

SORT?=/usr/bin/sort
PLIST=${WRKDIR}/plist

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
		<${FILESDIR}/mozconfig.in >${WRKSRC}/.mozconfig

# fix for Xft (thanks to marcus@)
post-patch:
	cd ${WRKSRC}/gfx/src/gtk;				\
	${REINPLACE_CMD} -e 's|X11/Xft/Xft\.h|X11/Xft/Xft2.h|g'	\
		nsDrawingSurfaceGTK.cpp	nsFontMetricsXft.h

pre-install:
	${RM} -f ${PLIST}
	${TOUCH} ${PLIST}

post-install:
	@${RM} -f ${PREFIX}/bin/phoenix
	@${LN} -s ${LOCAL_PREFIX}/bin/phoenix \
		${PREFIX}/bin/phoenix
	@${RM} -f ${PREFIX}/bin/phoenix-config
	@${LN} -s ${LOCAL_PREFIX}/bin/mozilla-config \
		${PREFIX}/bin/phoenix-config
	@${CAT} ${PKGMESSAGE} 2>/dev/null
	@${RM} -fr ${LOCAL_PREFIX}/share/idl
	@${RM} -fr ${LOCAL_PREFIX}/include
	-${RM} -f ${PLUGINSDIR}/libjavaplugin_oji.so
	-${LN} -sf \
	  ${JREDIR}/plugin/i386/ns600/libjavaplugin_oji.so \
	  ${PLUGINSDIR}/libjavaplugin_oji.so
	-${RM} -f ${PLIST}
	${ECHO_CMD} bin/phoenix >>${PLIST}
	${ECHO_CMD} bin/phoenix-config >>${PLIST}
	cd ${PREFIX}; \
	${FIND} ${LOCAL_SUBDIR} ! -type d | ${SORT} >>${PLIST}; \
	${FIND} ${LOCAL_SUBDIR} -type d -empty | ${SORT} \
	  | ${SED} -e "s:^:@exec /bin/mkdir -p %D/:" -e "s:$$: || true:" \
	  >> ${PLIST}; \
	${FIND} ${LOCAL_SUBDIR} -type d -empty | ${SORT} -r \
	  | ${SED} -e "s:^:@unexec /bin/rmdir %D/:" -e "s:$$: || true:" \
	  >> ${PLIST}; \
	${FIND} ${LOCAL_SUBDIR} -type d ! -empty | ${SORT} -r \
		| ${SED} -e "s:^:@dirrm :" >> ${PLIST}

.include <bsd.port.post.mk>
#EOF
