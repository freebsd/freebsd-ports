PORTNAME=	riemann-c-client
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://git.madhouse-project.org/algernon/${PORTNAME}/archive/

MAINTAINER=	dch@FreeBSD.org
COMMENT=	C library and command-line tool for Riemann
WWW=		https://git.madhouse-project.org/algernon/riemann-c-client

LICENSE=	EUPL12
LICENSE_FILE=	${WRKSRC}/LICENSES/EUPL-1.2.txt

WRKSRC=		${WRKDIR}/${PORTNAME}

BUILD_DEPENDS=	check>0:devel/check
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libjson-c.so:devel/json-c \
		libprotobuf-c.so:devel/protobuf-c

USES=		autoreconf gmake libtool pathfix pkgconfig

CONFIGURE_ARGS=	ac_cv_prog_ld_version_script=no
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
LDFLAGS+=	-Wl,--undefined-version

# Running |make test| isn't on poudriere menu yet, so force-feed
pre-install: do-test

.include <bsd.port.mk>
