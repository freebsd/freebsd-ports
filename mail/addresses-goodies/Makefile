PORTNAME=	addresses
DISTVERSION=	0.5.0
CATEGORIES=	mail gnustep
MASTER_SITES=	SAVANNAH/gap
PKGNAMESUFFIX=	-goodies${PKGNAMESUFFIX2}
DISTNAME=	Addresses-${DISTVERSION}

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Goodies for addressbook for GNUstep
WWW=		https://gap.nongnu.org/addresses/index.html

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libAddresses.so:mail/addresses

USES=		gnustep
USE_GNUSTEP=	back base build
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

MAKE_ENV+=	disable-ldapaddressbook=yes disable-vcfviewer=yes
ALL_TARGET=	goodies
INSTALL_TARGET=	goodies-install

post-install:
	@cd ${STAGEDIR}${PREFIX}/GNUstep/System/Tools && \
		${STRIP_CMD} adgnumailconverter adserver adtool

.include <bsd.port.mk>
