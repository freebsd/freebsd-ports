# $FreeBSD$

PORTNAME=	portfmt
PORTVERSION=	g20191001
CATEGORIES=	ports-mgmt

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Format FreeBSD Ports Makefiles

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	t6
GH_TAGNAME=	16a873c98e015383e38bc70927f56733526395c9
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
		lib/libportfmt.so \
		man/man1/portclippy.1.gz \
		man/man1/portedit.1.gz \
		man/man1/portfmt.1.gz

.include <bsd.port.mk>
