PORTNAME=	binbloom
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Raw binary firmware analysis software
WWW=		https://github.com/quarkslab/binbloom

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake

USE_GITHUB=	yes
GH_ACCOUNT=	quarkslab

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/binbloom \
		share/man/man1/binbloom.1.gz

.include <bsd.port.mk>
