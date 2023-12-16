PORTNAME=	libksba
PORTVERSION=	1.6.5
CATEGORIES=	security
MASTER_SITES=	GNUPG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to make X.509 certificates
WWW=		https://www.gnupg.org/aegypten2/

LICENSE=	GPLv2 GPLv3 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.GPLv2
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.GPLv3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPLv3

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error

USES=		cpe libtool perl5 tar:bzip2
USE_PERL5=	build

CONFIGURE_ARGS=	--enable-static
CONFIGURE_ENV=	PKG_CONFIG_PATH=${LOCALBASE}/libdata/pkgconfig
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=		ksba
PLIST_SUB=	PATCH_VERSION=${PORTVERSION:E}

CPE_VENDOR=	libksba_project

.include <bsd.port.mk>
