# $FreeBSD$

PORTNAME=	yank
DISTVERSION=	1.0.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/mptre/yank/releases/download/v${DISTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Yank terminal output to clipboard

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	xsel-conrad>=0:x11/xsel-conrad

MAKE_ARGS=	MANPREFIX=${PREFIX}/man
PLIST_FILES=	bin/yank \
		man/man1/yank.1.gz

.include <bsd.port.mk>
