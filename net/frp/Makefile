PORTNAME=	frp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.65.0
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reverse proxy to expose local server behind NAT/firewall to Internet
WWW=		https://github.com/fatedier/frp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:net:v0.8.0:net \
		golang:sys:v0.6.0:sys \
		golang:text:v0.8.0:text

GO_MODULE=	github.com/fatedier/frp
GO_TARGET=	./cmd/frpc ./cmd/frps

SUB_LIST=	DAEMON_USER=${DAEMON_USER}
USE_RC_SUBR=	${PORTNAME}s

OPTIONS_RADIO=			DAEMON_USER # also see https://github.com/fatedier/frp/issues/3417
OPTIONS_RADIO_DAEMON_USER=	ROOT NOBODY
OPTIONS_DEFAULT=		ROOT # to allow frp to read certificates

ROOT_VARS=	DAEMON_USER=root
NOBODY_VARS=	DAEMON_USER=nobody

DAEMON_USER_DESC=	Daemon user

ROOT_DESC=	Run as root
NOBODY_DESC=	Run as nobody

pre-patch:
.for m in net sys test
	${RM} -r ${WRKSRC}/vendor/golang.org/x/$m
	${LN} -s ${WRKDIR}/$m-* ${WRKSRC}/vendor/golang.org/x/$m
.endfor

post-install:
.for f in frpc.toml frps.toml
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${STAGEDIR}${PREFIX}/etc/${f}.sample
.endfor

.include <bsd.port.mk>
