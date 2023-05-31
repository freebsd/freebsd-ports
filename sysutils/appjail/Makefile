PORTNAME=	appjail
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Simple and easy-to-use tool for creating portable jails
WWW=		https://github.com/DtxdF/AppJail

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	appjail-devel

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF
GH_PROJECT=	AppJail

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
