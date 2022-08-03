PORTNAME=	frp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.43.0
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reverse proxy to expose local server behind NAT/firewall to Internet

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/fatedier/frp
GO_TARGET=	./cmd/frpc ./cmd/frps

USER=		nobody
SUB_LIST=	USER=${USER}
USE_RC_SUBR=	${PORTNAME}s

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/frps.ini ${STAGEDIR}${PREFIX}/etc/frps.ini.sample

.include <bsd.port.mk>
