# $FreeBSD$

PORTNAME=	zsh-syntax-highlighting
PORTVERSION=	20160816
CATEGORIES=	textproc

MAINTAINER=	jrm@ftfl.ca
COMMENT=	Fish shell syntax highlighting for Zsh

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	zsh>=4.3.17:shells/zsh

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	zsh-users
GH_TAGNAME=	11c9081

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
