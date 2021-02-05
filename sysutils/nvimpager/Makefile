# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nvimpager
PORTVERSION=	0.9
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Use NeoVim as a pager, with full syntax highlighting

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		nvim:editors/neovim

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	lucc

MAKEFILE=	makefile
NO_BUILD=	yes

.include <bsd.port.mk>
