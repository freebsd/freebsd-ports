PORTNAME=	tcping
PORTVERSION=	1.20.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net
PKGNAMEPREFIX=	go-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line utility to ping TCP ports written in Go
WWW=		https://github.com/pouriyajamshidi/tcping

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	pouriyajamshidi

GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/gotcping

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/gotcping

.include <bsd.port.mk>
