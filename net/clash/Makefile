PORTNAME=	clash
DISTVERSIONPREFIX=	v
DISTVERSION=	1.18.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rule-based tunnel in Go
WWW=		https://github.com/Dreamacro/clash # actually coming from the fork https://github.com/wangtz0607/clash

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.21,modules cpe

CPE_VENDOR=	clash_project

GO_MODULE=	github.com/Dreamacro/clash

PLIST_FILES=	bin/${PORTNAME}

PORTSCOUT=	limit:^[0-9\.]*$$

pre-patch:
	@cd ${WRKSRC} && ${CP} listener/redir/tcp_linux.go listener/redir/tcp_freebsd.go

.include <bsd.port.mk>
