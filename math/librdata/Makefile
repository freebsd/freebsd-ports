PORTNAME=	librdata
PORTVERSION=	0.1.0.g20210224
CATEGORIES=	math

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read and write R data frames from C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf compiler:c11 libtool gettext-tools

USE_GITHUB=	yes
GH_ACCOUNT=	WizardMac
GH_TAGNAME=	4a80bf3

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/rdata_io_unistd.h ${STAGEDIR}${PREFIX}/include/rdata_io_unistd.h

.include <bsd.port.mk>
