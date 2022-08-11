PORTNAME=	UniversalFeedCreator
PORTVERSION=	1.8.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	RSS and Atom feed generator by Kai Blankenhorn

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

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
