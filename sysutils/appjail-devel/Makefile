PORTNAME=	appjail
DISTVERSIONPREFIX=	v
DISTVERSION=	g20230515
CATEGORIES=	sysutils
PKGNAMESUFFIX= -devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Simple and easy-to-use tool for creating portable jails (devel)
WWW=		https://github.com/DtxdF/AppJail

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	appjail

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF
GH_PROJECT=	AppJail
GH_TAGNAME=	f32080a9de86dfe1acd80b8728ad637994227a9a

ALL_TARGET=	utils-strip

PORTDOCS=	README.md

OPTIONS_DEFINE=			DEBOOTSTRAP DOCS GIT
DEBOOTSTRAP_DESC=		Support for Debian and Ubuntu jails
DEBOOTSTRAP_RUN_DEPENDS=	debootstrap>0:sysutils/debootstrap
GIT_RUN_DEPENDS=		git>0:devel/git

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
