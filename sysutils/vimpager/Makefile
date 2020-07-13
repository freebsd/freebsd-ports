# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vimpager
DISTVERSION=	2.06.20200712
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Use Vim/NeoVim as a pager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	rkitover
GH_TAGNAME=	85004fd

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	BACKEND
OPTIONS_DEFAULT=VIM

OPTIONS_SINGLE_BACKEND=	NEOVIM VIM VIMCONSOLE
BACKEND_DESC=	Choose your Vim backend
NEOVIM_DESC=	NeoVim
VIM_DESC=	Full Vim (vim)
VIMCONSOLE_DESC=Console-only Vim (vim-console)

NEOVIM_RUN_DEPENDS=	nvim:editors/neovim
VIM_RUN_DEPENDS=	vim:editors/vim
VIMCONSOLE_RUN_DEPENDS=	vim:editors/vim-console

.include <bsd.port.mk>
