PORTNAME=	benthos
DISTVERSIONPREFIX=	v
DISTVERSION=	4.27.0
PORTREVISION=	12
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Stream processor for a wide array of data sources and sinks
WWW=		https://www.benthos.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Superseded by net/redpanda-connect
EXPIRATION_DATE=	2025-09-11

USES=		go:modules
USE_RC_SUBR=	benthos

GO_MODULE=	github.com/benthosdev/benthos/v4
GO_TARGET=	./cmd/benthos

USERS=		benthos
GROUPS=		benthos

PLIST_FILES=	bin/benthos \
		"@dir(,,755) %%ETCDIR%%" \
		"@sample %%ETCDIR%%/config.yaml.sample"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/config.yaml ${STAGEDIR}${ETCDIR}/config.yaml.sample

.include <bsd.port.mk>
