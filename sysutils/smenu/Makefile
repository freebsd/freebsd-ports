PORTNAME=	smenu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.19
CATEGORIES=	sysutils

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Terminal utility to interactively filter text

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=	localbase ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	p-gen

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/smenu \
		man/man1/smenu.1.gz

.include <bsd.port.mk>
