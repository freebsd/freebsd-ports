# $FreeBSD$

PORTNAME=	portfmt
PORTVERSION=	g20190529
CATEGORIES=	ports-mgmt

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Format FreeBSD Ports Makefiles

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	colordiff:textproc/colordiff

USE_GITHUB=	yes
GH_ACCOUNT=	t6
GH_TAGNAME=	464a42f6ab8a5fd17e7f752c028bf7f8de53bf21

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
