PORTNAME=	vimpager
DISTVERSION=	2.06.20250412
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/rkitover/vimpager/releases/download/${DISTVERSION:R}/
DISTFILES+=	man${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Use Vim/NeoVim as a pager (${FLAVOR:U} flavor)
WWW=		https://github.com/rkitover/vimpager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	bats:devel/bats-core

FLAVORS=	console gtk2 gtk3 motif tiny x11 neovim
FLAVOR?=	${FLAVORS:[1]}

console_RUN_DEPENDS=	${LOCALBASE}/bin/vim:editors/vim@console
gtk2_PKGNAMESUFFIX=	-gtk2
gtk2_RUN_DEPENDS=	${LOCALBASE}/bin/vim:editors/vim@gtk2
gtk3_PKGNAMESUFFIX=	-gtk3
gtk3_RUN_DEPENDS=	${LOCALBASE}/bin/vim:editors/vim@gtk3
motif_PKGNAMESUFFIX=	-motif
motif_RUN_DEPENDS=	${LOCALBASE}/bin/vim:editors/vim@motif
neovim_PKGNAMESUFFIX=	-neovim
neovim_RUN_DEPENDS=	${LOCALBASE}/bin/nvim:editors/neovim
tiny_PKGNAMESUFFIX=	-tiny
tiny_RUN_DEPENDS=	${LOCALBASE}/bin/vim:editors/vim@tiny
x11_PKGNAMESUFFIX=	-x11
x11_RUN_DEPENDS=	${LOCALBASE}/bin/vim:editors/vim@x11

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	rkitover
GH_TAGNAME=	842f746

TEST_TARGET=	test
TESTING_UNSAFE=	yes

# Register conflicts with all other flavors
CONFLICTS_INSTALL=	${FLAVORS:N${FLAVOR}:S/^/vimpager-/}

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-docs-off

post-extract:
	@(${MKDIR} ${WRKSRC}/man && \
		${MV} ${WRKDIR}/*.1 \
		${WRKSRC}/man)

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/vimpagerrc \
		${STAGEDIR}${PREFIX}/etc/vimpagerrc.sample

.include <bsd.port.mk>
