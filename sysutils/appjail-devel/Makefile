PORTNAME=	appjail
DISTVERSIONPREFIX=	v
DISTVERSION=	g20230518
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
GH_TAGNAME=	357c296ed3d9e1b5e0bca0caec726c14bc79d35b

ALL_TARGET=	utils-strip

PORTDOCS=	README.md

SUB_FILES=	pkg-message

OPTIONS_DEFINE=			DEBOOTSTRAP DOCS DOAS GIT
DEBOOTSTRAP_DESC=		Support for Debian and Ubuntu jails
DEBOOTSTRAP_RUN_DEPENDS=	debootstrap>0:sysutils/debootstrap
DOAS_DESC=			Add support for unprivileged users
DOAS_RUN_DEPENDS=		doas>0:security/doas
GIT_RUN_DEPENDS=		git>0:devel/git

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

post-install:
	${MKDIR} ${STAGEDIR}/${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/share/appjail/files/default.conf ${STAGEDIR}/${ETCDIR}/appjail.conf.sample

.include <bsd.port.mk>
