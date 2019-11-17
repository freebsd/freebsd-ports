# $FreeBSD$

PORTNAME=	portfmt
PORTVERSION=	g20191117
CATEGORIES=	ports-mgmt

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Format FreeBSD Ports Makefiles

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	t6
GH_TAGNAME=	9121f6116898888fe3312fa20160b06c5271625e
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	LDFLAGS="${LDFLAGS}" \
		PREFIX="${PREFIX}"
MAKE_ARGS=	INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
TEST_TARGET=	test

PLIST_FILES=	bin/portclippy \
		bin/portedit \
		bin/portfmt \
		bin/portscan \
		lib/libportfmt.so \
		man/man1/portclippy.1.gz \
		man/man1/portedit.1.gz \
		man/man1/portfmt.1.gz \
		man/man1/portscan.1.gz

.include <bsd.port.mk>
