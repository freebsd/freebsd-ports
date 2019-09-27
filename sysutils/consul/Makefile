# $FreeBSD$

PORTNAME=	consul
PORTVERSION=	1.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Service discovery and configuration made easy

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp

GO_BUILDFLAGS=	-ldflags="\
		-X github.com/hashicorp/consul/version.Version=${PORTVERSION} \
		-X github.com/hashicorp/consul/version.VersionPrerelease= \
		-X github.com/hashicorp/consul/version.GitDescribe=v${PORTVERSION} \
		"

USE_RC_SUBR=	consul

PLIST_FILES=	bin/consul

USERS=		consul
GROUPS=		consul

post-extract:
	${MKDIR} ${WRKSRC}/vendor/github.com/${GH_ACCOUNT}/${PORTNAME}
	${LN} -s ${WRKSRC}/api ${WRKSRC}/vendor/github.com/${GH_ACCOUNT}/${PORTNAME}/api
	${LN} -s ${WRKSRC}/sdk ${WRKSRC}/vendor/github.com/${GH_ACCOUNT}/${PORTNAME}/sdk

.include <bsd.port.mk>
