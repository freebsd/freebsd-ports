# $FreeBSD$

PORTNAME=	zsh-syntax-highlighting
DISTVERSION=	0.6.0-243
DISTVERSIONSUFFIX=	-g82cf252
PORTEPOCH=	1
CATEGORIES=	textproc

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Fish shell syntax highlighting for Zsh

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	zsh>=5.4:shells/zsh

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	zsh-users

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
