PORTNAME=	appjail
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.0
CATEGORIES=	sysutils

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Simple and easy-to-use tool for creating portable jails
WWW=		https://github.com/DtxdF/AppJail/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF
GH_PROJECT=	AppJail

ALL_TARGET=	utils-strip

CONFLICTS=	appjail-devel

PORTDOCS=	README.md

OPTIONS_DEFINE=	DEBOOTSTRAP DOAS DOCS GIT

DEBOOTSTRAP_DESC=	Support for Debian and Ubuntu jails
DOAS_DESC=		Add support for unprivileged users

DEBOOTSTRAP_RUN_DEPENDS=	debootstrap>0:sysutils/debootstrap
DOAS_RUN_DEPENDS=		doas>0:security/doas
GIT_RUN_DEPENDS=		git>0:devel/git

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

post-install:
	${MKDIR} ${STAGEDIR}/${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/share/examples/appjail/appjail.conf ${STAGEDIR}/${ETCDIR}/appjail.conf.sample

.include <bsd.port.mk>
