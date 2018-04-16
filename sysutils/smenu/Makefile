# $FreeBSD$

PORTNAME=	smenu
PORTVERSION=	0.9.12
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Terminal utility to interactively filter text

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=	localbase ncurses:port

USE_GITHUB=	yes
GH_ACCOUNT=	p-gen
GH_TAGNAME=	0ff0326

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/smenu \
		man/man1/smenu.1.gz

.include <bsd.port.mk>
