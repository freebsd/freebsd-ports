PORTNAME=	smenu
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	sysutils

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Terminal utility to interactively filter text
WWW=		https://github.com/p-gen/smenu

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	localbase ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	p-gen

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/smenu \
		man/man1/smenu.1.gz

.include <bsd.port.mk>
