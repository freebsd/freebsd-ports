# New ports collection makefile for:	mozilla-thunderbird
# Date created:			4 September 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thunderbird
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	thunderbird/releases/${PORTVERSION}
PKGNAMEPREFIX=	mozilla-
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

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
USE_GNOME=	gtk20 libidl

NO_MTREE=		yes
WRKSRC=			${WRKDIR}/mozilla
LOCAL_SUBDIR=		lib/${PORTNAME}
LOCAL_PREFIX=		${PREFIX}/${LOCAL_SUBDIR}

NOT_FOR_ARCHS=		amd64

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CONFIGURE_ENV+=		WITH_REORDER=yes
.endif # ${ARCH} == "i386"

.if ${ARCH} == "alpha" && ${OSVERSION} < 500035
IGNORE=	"core dumps at runtime"
.endif # ${ARCH} == "alpha" && ${OSVERSION} < 500035

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

CPPFLAGS+=		-I${X11BASE}/include
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		-L${X11BASE}/lib
LIBS+=			${PTHREAD_LIBS}

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
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/nsprpub/configure
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/nsprpub/configure \
		${WRKSRC}/security/coreconf/FreeBSD.mk \
		${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
		${WRKSRC}/js/src/Makefile.in

pre-install:
	${RM} -fr ${LOCAL_PREFIX}

post-install:
	${RM} -f ${PREFIX}/bin/thunderbird
	${LN} -s ${LOCAL_PREFIX}/bin/thunderbird \
		${PREFIX}/bin/thunderbird
	${RM} -f ${PREFIX}/bin/thunderbird-config
	${LN} -s ${LOCAL_PREFIX}/bin/mozilla-config \
		${PREFIX}/bin/thunderbird-config
	${RM} -fr ${LOCAL_PREFIX}/share/idl
	${RM} -fr ${LOCAL_PREFIX}/include

cons-plist:
	-${RM} -f ${PLIST}
	${TOUCH} ${PLIST}
	${ECHO_CMD} bin/thunderbird >>${PLIST}
	${ECHO_CMD} bin/thunderbird-config >>${PLIST}
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

.include <bsd.port.post.mk>
