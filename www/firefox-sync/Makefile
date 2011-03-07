# New ports collection makefile for:	weave
# Date created:				31 Aug 2009
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	firefox-sync
PORTVERSION=	1.6.3
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	http://hg.mozilla.org/services/fx-sync/archive/${DISTVERSION}${EXTRACT_SUFX}/

MAINTAINER=	magik@roorback.net
COMMENT=	Mozilla extension to synchronize Firefox data

BUILD_DEPENDS=	${LOCALBASE}/lib/libxul/xpidl:${PORTSDIR}/www/libxul
RUN_DEPENDS=	${LOCALBASE}/lib/libxul/xpidl:${PORTSDIR}/www/libxul

ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=yes
WRKSRC=		${WRKDIR}/fx-sync-${DISTVERSION}

OPTIONS=	FF35 "Build for Firefox 3.5 instead of 3.6" Off

.include <bsd.port.options.mk>

.if defined(WITHOUT_FF35)
USE_FIREFOX_BUILD=	36
AMD64_ARCH=	amd64
.else
USE_FIREFOX_BUILD=	35
AMD64_ARCH=	x86_64
.endif

REVID=		d52662c1c99b
.if ${ARCH} == i386
PLATFORM=	FreeBSD_x86-gcc3
.elif ${ARCH} == amd64
PLATFORM=	FreeBSD_${AMD64_ARCH}-gcc3
.else
PLATFORM=	dummy
IGNORE=		unsupported platform
.endif

GMAKE_FLAGS=	sdkdir=${PREFIX}/lib/firefox3/sdk release_build=1 platform_target=${PLATFORM} TOPSRCDIR=${WRKSRC}
ALL_TARGET=	${GMAKE_FLAGS} crypto crypto-obsolete-build build
INSTALL_TARGET=	${GMAKE_FLAGS} xpi

XPI_ID=		{340c2bbc-ce74-4362-90b5-7c26312808ef}
XPI_DIR=	${PREFIX}/lib/xpi/${XPI_ID}

PLIST_SUB+=	XPI_XPIDIR="${XPI_DIR:S,^${PREFIX}/,,}" \
		XPI_XPIID=${XPI_ID} \
		PLATFORM=${PLATFORM}

post-patch:
	@${REINPLACE_CMD} -e "s|\$$(shell hg tip --template '{node\|short}')|${REVID}|g" ${WRKSRC}/Makefile
.if ${PLATFORM} == FreeBSD_x86_64-gcc3
	${REINPLACE_CMD} -e 's|arch = amd64|arch = x86_64|g' ${WRKSRC}/crypto-obsolete/src/Makefile
.endif

post-install:
	${MKDIR} ${XPI_DIR}
	(cd ${XPI_DIR}; tar -xf ${WRKSRC}/dist/xpi/weave-${DISTVERSION}-rel.xpi)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${XPI_DIR}/
	${FIND} ${XPI_DIR}/ -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	${FIND} ${XPI_DIR}/ -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	${MKDIR} ${PREFIX}/lib/firefox3/extensions
	${LN} -sf ${XPI_DIR} ${PREFIX}/lib/firefox3/extensions

.include <bsd.port.mk>
