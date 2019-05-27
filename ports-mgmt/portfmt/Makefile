# $FreeBSD$

PORTNAME=	portfmt
PORTVERSION=	g20190527
CATEGORIES=	ports-mgmt

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Format FreeBSD Ports Makefiles

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	colordiff:textproc/colordiff

USE_GITHUB=	yes
GH_ACCOUNT=	t6
GH_TAGNAME=	c8ac080432d2bcbca21a0e3019ad7a068ed698f

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	LDFLAGS="${LDFLAGS}" \
		PREFIX="${PREFIX}"
MAKE_ARGS=	INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
TEST_TARGET=	test

PLIST_FILES=	bin/portclippy \
		bin/portedit \
		bin/portfmt \
		man/man1/portfmt.1.gz

.include <bsd.port.mk>
