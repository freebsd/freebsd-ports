PORTNAME=	appjail
DISTVERSION=	4.5.0.20251106
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Simple and easy-to-use tool for creating portable jails (devel)
WWW=		https://github.com/DtxdF/AppJail

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	appjail

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF
GH_PROJECT=	AppJail
GH_TAGNAME=	edba3f1901e3a41b024b909a8f5d5a51ebb483f7

MAKE_ARGS=	APPJAIL_VERSION=${DISTVERSION}+${GH_TAGNAME}
ALL_TARGET=	utils-strip

SUB_FILES=	pkg-message

PORTDOCS=	README.md

OPTIONS_DEFINE=		DEBOOTSTRAP DOAS DOCS GIT OCI PKG
OPTIONS_DEFAULT=	PKG

DEBOOTSTRAP_DESC=	Support for Debian and Ubuntu jails
DOAS_DESC=		Add support for unprivileged users
OCI_DESC=		Add support for OCI
PKG_DESC=		Add support for pkgbase

DEBOOTSTRAP_RUN_DEPENDS=	debootstrap>0:sysutils/debootstrap
DOAS_RUN_DEPENDS=		doas>0:security/doas
GIT_RUN_DEPENDS=		git>0:devel/git
OCI_RUN_DEPENDS=		buildah>0:sysutils/buildah \
				jq>0:textproc/jq
PKG_RUN_DEPENDS=		${LOCALBASE}/sbin/pkg:${PKG_ORIGIN}

post-install:
	${MKDIR} ${STAGEDIR}/${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/share/examples/appjail/appjail.conf ${STAGEDIR}/${ETCDIR}/appjail.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
