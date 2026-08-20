PORTNAME=	appjail
DISTVERSION=	5.4.0.20260820
PORTEPOCH=	1
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Simple and easy-to-use tool for creating portable jails (devel)
WWW=		https://github.com/DtxdF/AppJail

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF
GH_PROJECT=	AppJail
GH_TAGNAME=	f0b7de8b688ce88b8ff9eaa946a9d96a63f8b825

MAKE_ARGS=	APPJAIL_VERSION=${DISTVERSION}+${GH_TAGNAME}
ALL_TARGET=	utils-strip

CONFLICTS=	appjail

SUB_FILES=	pkg-message

PORTDOCS=	README.md

OPTIONS_DEFINE=		DEBOOTSTRAP DOAS DOCS GIT OCI PKGBASE X11
OPTIONS_DEFAULT=	OCI PKGBASE
OPTIONS_RADIO=		SECRETS
OPTIONS_RADIO_SECRETS=	AGE RAGE

AGE_DESC=		Use security/age as secrets backend
DEBOOTSTRAP_DESC=	Support for Debian and Ubuntu jails
DOAS_DESC=		Add support for unprivileged users
OCI_DESC=		Add support for OCI
PKGBASE_DESC=		Add support for pkgbase
RAGE_DESC=		Use security/rage as secrets backend
X11_DESC=		Add support for x11

AGE_RUN_DEPENDS=		age:security/age
DEBOOTSTRAP_RUN_DEPENDS=	debootstrap>0:sysutils/debootstrap
DOAS_RUN_DEPENDS=		doas>0:security/doas
GIT_RUN_DEPENDS=		git>0:devel/git
OCI_RUN_DEPENDS=		buildah>0:sysutils/buildah \
				jq>0:textproc/jq
PKGBASE_RUN_DEPENDS=		${LOCALBASE}/sbin/pkg:${PKG_ORIGIN}
RAGE_RUN_DEPENDS=		rage:security/rage-encryption
X11_RUN_DEPENDS=		su-exec:security/su-exec \
				xauth:x11/xauth \
				xdotool:x11/xdotool \
				Xephyr:x11-servers/xorg-server@xephyr \
				xev:x11/xev \
				xseticon:x11/xseticon

post-install:
	${MKDIR} ${STAGEDIR}/${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/share/examples/appjail/appjail.conf ${STAGEDIR}/${ETCDIR}/appjail.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
