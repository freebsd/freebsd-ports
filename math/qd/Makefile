PORTNAME=	qd
DISTVERSION=	2.3.23
CATEGORIES=	math
MASTER_SITES=	https://www.davidhbailey.com/dhbsoftware/

MAINTAINER=	fortran@FreeBSD.org
COMMENT=	Double-Double and Quad-Double Arithmetic

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fortran libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

TEST_WRKSRC=	${WRKSRC}/tests
TEST_TARGET=	demo

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
