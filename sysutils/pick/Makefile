# $FreeBSD$

PORTNAME=	pick
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/mptre/pick/releases/download/v${PORTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Tool for choosing one option from a set of choices with an interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ncurses
HAS_CONFIGURE=	yes
MAKE_ARGS=	INSTALL="${INSTALL_PROGRAM}"
PLIST_FILES=	bin/pick \
		man/man1/pick.1.gz

.include <bsd.port.mk>
