# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	UniversalFeedCreator
PORTVERSION=	1.8.3.1
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	www

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	RSS and Atom feed generator by Kai Blankenhorn

USES=		php

USE_GITHUB=	yes
GH_ACCOUNT=	flack

NO_BUILD=	YES

DOTFILES=	.editorconfig .gitattributes .gitignore .travis.yml

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${STAGEDIR}/${DATADIR}

	# install everything +x, because it's easier
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${DATADIR})

.for _dot in ${DOTFILES}
	${RM} ${STAGEDIR}/${DATADIR}/${_dot}
.endfor

.include <bsd.port.post.mk>
