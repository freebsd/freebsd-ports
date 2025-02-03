PORTNAME=	appjail
DISTVERSION=	3.6.0.20250130
PORTEPOCH=	1
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Simple and easy-to-use tool for creating portable jails (devel)
WWW=		https://github.com/DtxdF/AppJail

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	appjail

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF
GH_PROJECT=	AppJail
GH_TAGNAME=	725e7a27cee28ab0168f7c62cecb1811b5422c11

MAKE_ARGS=	APPJAIL_VERSION=${DISTVERSION}+${GH_TAGNAME}
ALL_TARGET=	utils-strip

SUB_FILES=	pkg-message

PORTDOCS=	README.md

OPTIONS_DEFINE=			DEBOOTSTRAP DOAS DOCS GIT OCI

DEBOOTSTRAP_DESC=		Support for Debian and Ubuntu jails
DOAS_DESC=			Add support for unprivileged users
OCI_DESC=			Add support for OCI

DEBOOTSTRAP_RUN_DEPENDS=	debootstrap>0:sysutils/debootstrap
DOAS_RUN_DEPENDS=		doas>0:security/doas
GIT_RUN_DEPENDS=		git>0:devel/git
OCI_RUN_DEPENDS=		buildah>0:sysutils/buildah \
				jq>0:textproc/jq

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

post-install:
	${MKDIR} ${STAGEDIR}/${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/share/examples/appjail/appjail.conf ${STAGEDIR}/${ETCDIR}/appjail.conf.sample

.include <bsd.port.mk>
