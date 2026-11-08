PORTNAME=	git-proxy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	ports-mgmt

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Caching proxy for package registries, including FreeBSD pkg
WWW=		https://github.com/git-pkgs/proxy

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules
USE_GITHUB=	yes
GH_ACCOUNT=	git-pkgs
GH_PROJECT=	proxy
USE_RC_SUBR=	git_proxy

GO_MOD_DIST=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${GH_TAGNAME}/
GO_MODULE=	github.com/git-pkgs/proxy
GO_TARGET=	./cmd/proxy:${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-X main.Version=${DISTVERSIONFULL}"

SUB_FILES=	config.yaml.sample pkg-message
SUB_LIST=	GIT_PROXY_DBDIR=${GIT_PROXY_DBDIR} \
		GIT_PROXY_USER=${USERS}

USERS=		www
GROUPS=		www

PLIST_FILES=	"@sample ${ETCDIR}/config.yaml.sample" \
		bin/${PORTNAME}
PORTEXAMPLES=	config.example.yaml

OPTIONS_DEFINE=	EXAMPLES

GIT_PROXY_DBDIR=	/var/db/${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/config.yaml.sample ${STAGEDIR}${ETCDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config.example.yaml ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
