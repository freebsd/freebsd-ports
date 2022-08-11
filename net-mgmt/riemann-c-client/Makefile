PORTNAME=	riemann-c-client
PORTVERSION=	2.1.0
CATEGORIES=	net-mgmt
MASTER_SITES=	https://git.madhouse-project.org/algernon/${PORTNAME}/archive/

MAINTAINER=	dch@FreeBSD.org
COMMENT=	C library and command-line tool for Riemann

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}

BUILD_DEPENDS=	check>0:devel/check
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libjson-c.so:devel/json-c \
		libprotobuf-c.so:devel/protobuf-c

USES=		autoreconf gmake libtool pathfix pkgconfig

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

post-patch:
	@${REINPLACE_CMD} 's/-ldl//' ${WRKSRC}/Makefile.am

# Running |make test| isn't on poudriere menu yet, so force-feed
pre-install: do-test

.include <bsd.port.mk>
