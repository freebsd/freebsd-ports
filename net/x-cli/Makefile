PORTNAME=	x-cli
PORTVERSION=	5.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line power tool for Twitter
WWW=		https://github.com/sferik/x-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo ssl

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PLIST_FILES=	bin/x

USE_GITHUB=	yes
GH_ACCOUNT=	sferik

.include <bsd.port.mk>
