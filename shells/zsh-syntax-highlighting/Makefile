# $FreeBSD$

PORTNAME=	zsh-syntax-highlighting
DISTVERSION=	0.7.1
PORTEPOCH=	1
CATEGORIES=	shells

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Fish shell syntax highlighting for Zsh

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	zsh>=5.4:shells/zsh

USE_GITHUB=	yes
GH_ACCOUNT=	zsh-users

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
