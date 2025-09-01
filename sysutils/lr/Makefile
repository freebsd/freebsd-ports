PORTNAME=	lr
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	List files, recursively
WWW=		https://github.com/leahneukirchen/lr/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	leahneukirchen

MAKE_ARGS=	CFLAGS="${CFLAGS}" \
		PREFIX="${PREFIX}"

OPTIONS_DEFINE=		CONTRIB EMACS NEOVIM VIM
OPTIONS_DEFAULT=	CONTRIB EMACS NEOVIM VIM
OPTIONS_SUB=	yes

CONTRIB_DESC=	Contrib scripts
EMACS_DESC=	Emacs plugin
NEOVIM_DESC=	Neovim plugin
VIM_DESC=	Vim plugin

CONTRIB_RUN_DEPENDS=	xe:sysutils/xe

EMACS_USES=	emacs
EMACS_VARS=	EMACS_NO_DEPENDS=yes

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
