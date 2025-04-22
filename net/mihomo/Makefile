PORTNAME=	mihomo
DISTVERSIONPREFIX=	v
DISTVERSION=	1.19.5
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rule-based tunnel in Go
WWW=		https://github.com/MetaCubeX/mihomo/tree/Alpha

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.21,modules cpe

CPE_VENDOR=	clash_project

GO_MODULE=	github.com/metacubex/mihomo

PLIST_FILES=	bin/${PORTNAME}

PORTSCOUT=	limit:^[0-9\.]*$$

pre-patch:
	@cd ${WRKSRC} && ${CP} listener/redir/tcp_linux.go listener/redir/tcp_freebsd.go

.include <bsd.port.mk>
