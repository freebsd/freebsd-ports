PORTNAME=	netdata-go
DISTVERSIONPREFIX=	v
DISTVERSION=	0.57.2
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	External netdata collection plugin written in Go
WWW=		https://github.com/netdata/go.d.plugin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.21,modules

GO_MODULE=	github.com/netdata/go.d.plugin
GO_TARGET=	./cmd/godplugin:${PREFIX}/libexec/netdata/plugins.d/god.plugin

post-patch:
	${REINPLACE_CMD} -e 's|/etc/netdata|${PREFIX}/etc/netdata|g' ${WRKSRC}/cmd/godplugin/main.go

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/netdata/conf.d
	${INSTALL_DATA} ${WRKSRC}/config/go.d.conf ${STAGEDIR}${PREFIX}/lib/netdata/conf.d/go.d.conf.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/netdata/conf.d/go.d
	cd ${WRKSRC}/config/go.d && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/netdata/conf.d/go.d
	(for file in ${STAGEDIR}${PREFIX}/lib/netdata/conf.d/go.d/*.conf; do \
		${MV} $$file $$file".sample"; \
	done)

.include <bsd.port.mk>
