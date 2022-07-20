PORTNAME=	nvimpager
PORTVERSION=	0.10.4
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Use NeoVim as a pager, with full syntax highlighting

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		nvim:editors/neovim \
		scdoc:textproc/scdoc

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	lucc

MAKEFILE=	makefile
NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
