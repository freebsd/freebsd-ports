PORTNAME=	frp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.45.0
PORTREVISION=	6
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reverse proxy to expose local server behind NAT/firewall to Internet
WWW=		https://github.com/fatedier/frp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:net:v0.8.0:net \
		golang:sys:v0.6.0:sys \
		golang:text:v0.8.0:text

GO_MODULE=	github.com/fatedier/frp
GO_TARGET=	./cmd/frpc ./cmd/frps

USER=		nobody
SUB_LIST=	USER=${USER}
USE_RC_SUBR=	${PORTNAME}s

pre-patch:
.for m in net sys test
	${RM} -r ${WRKSRC}/vendor/golang.org/x/$m
	${LN} -s ${WRKDIR}/$m-* ${WRKSRC}/vendor/golang.org/x/$m
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/frps.ini ${STAGEDIR}${PREFIX}/etc/frps.ini.sample

.include <bsd.port.mk>
