# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	firetray
DISTVERSION=	0.2.8
PORTREVISION=	2
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	avg@icyb.net.ua
COMMENT=	System tray add-on for firefox, thunderbird, seamonkey, etc

PATCH_DEPENDS=	nspr>=4.8:${PORTSDIR}/devel/nspr

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05
BROKEN=		does not build

USE_ZIP=	yes
USE_GECKO=	libxul19
USE_SCONS=	yes
USE_PKGCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
GECKO_CONFIG=	${LOCALBASE}/bin/pkg-config ${GECKO:S/19//}

BUILD_SH_FLAGS=	--dynamic-linking \
		--gecko-sdk-bin=`${DIRNAME} ${XPIDL:S/19//}` \
		--gecko-sdk-lib=`${GECKO_CONFIG} --variable=sdkdir`/lib \
		--gecko-sdk-idl=`${GECKO_CONFIG} --variable=idldir` \
		--gecko-sdk-include=`${GECKO_CONFIG} --variable=includedir`
NSPR_INCLUDE=	`${LOCALBASE}/bin/pkg-config nspr --variable=includedir`

PLIST_DIRS=	${DATADIR:S,${PREFIX}/,,}
PLIST_FILES=	${DATADIR:S,${PREFIX}/,,}/${PORTNAME}.xpi

post-patch:
	@${REINPLACE_CMD} s,/usr/include/nspr,${NSPR_INCLUDE}, \
	    ${WRKSRC}/components/SConscript

do-build:
	cd ${WRKSRC} && ./build.sh ${BUILD_SH_FLAGS}

do-install:
	${MKDIR} ${DATADIR} && \
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.xpi ${DATADIR}

.include <bsd.port.mk>
