# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	lr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	List files, recursively

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	chneukirchen

MAKE_ARGS=	CFLAGS="${CFLAGS}" \
		PREFIX="${PREFIX}" \
		MANDIR="${PREFIX}/man"

OPTIONS_DEFINE=	CONTRIB EMACS NEOVIM VIM
OPTIONS_DEFAULT=	CONTRIB EMACS NEOVIM VIM

CONTRIB_DESC=	Contrib scripts
EMACS_DESC=	Emacs plugin
NEOVIM_DESC=	Neovim plugin
VIM_DESC=	Vim plugin

OPTIONS_SUB=	yes
EMACS_USE=	emacs=yes
EMACS_NO_BUILD_DEPENDS=	yes
EMACS_NO_RUN_DEPENDS=	yes

CONTRIB_RUN_DEPENDS=	xe:sysutils/xe

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lr

post-install-CONTRIB-on:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/lrls \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/lrocate \
		${STAGEDIR}${PREFIX}/bin

post-install-EMACS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/lr.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/lr.el

post-install-VIM-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/vim/vimfiles/plugin
	${INSTALL_DATA} ${WRKSRC}/contrib/lr.vim \
		${STAGEDIR}${PREFIX}/share/vim/vimfiles/plugin/

post-install-NEOVIM-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/nvim/runtime/plugin
	${INSTALL_DATA} ${WRKSRC}/contrib/lr.vim \
		${STAGEDIR}${PREFIX}/share/nvim/runtime/plugin/

.include <bsd.port.mk>
