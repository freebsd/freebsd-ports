PORTNAME=	addresses
DISTVERSION=	0.5.0
CATEGORIES=	mail gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	Addresses-${DISTVERSION}

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Versatile addressbook for GNUstep
WWW=		https://gap.nongnu.org/addresses/index.html

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		gnustep
USE_GNUSTEP=	back base build gui
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

post-install:
		@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/AddressManager.app/AddressManager \
			${STAGEDIR}${PREFIX}/GNUstep/System/Library/Frameworks/AddressView.framework/Versions/${DISTVERSION}/libAddressView.so.${DISTVERSION} \
			${STAGEDIR}${PREFIX}/GNUstep/System/Library/Frameworks/Addresses.framework/Versions/${DISTVERSION}/libAddresses.so.${DISTVERSION}

.include <bsd.port.mk>
