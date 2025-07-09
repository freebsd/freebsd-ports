PORTNAME=	mackerel-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.85.0
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Agent program to post your hosts' metrics to mackerel.io
WWW=		https://mackerel.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.24
USE_RC_SUBR=	mackerel_agent
GO_MODULE=	github.com/mackerelio/mackerel-agent

post-patch:
	${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|" ${WRKSRC}/config/config_unix.go

post-stage:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/mackerel-agent.sample.conf ${STAGEDIR}${ETCDIR}
	${MV} ${STAGEDIR}${ETCDIR}/mackerel-agent.sample.conf \
		${STAGEDIR}${ETCDIR}/mackerel-agent.conf.sample

.include <bsd.port.mk>
