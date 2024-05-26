PORTNAME=	nvimpager
PORTVERSION=	0.13.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Use NeoVim as a pager, with full syntax highlighting
WWW=		https://github.com/lucc/nvimpager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc
RUN_DEPENDS=	bash:shells/bash \
		nvim:editors/neovim

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	lucc

MAKEFILE=	makefile
NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
