# Created by: Mark Felder <feld@FreeBSD.org>

PORTNAME=	rubywarden
DISTVERSION=	0.0.0.20200226
PORTREVISION=	0
CATEGORIES=	security www

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Ruby implementation of the BitWarden API

LICENSE=	ISCL

# Port is not maintained anymore:
# https://github.com/jcs/rubywarden
BROKEN_RUBY27=	yes

RUN_DEPENDS=	rubygem-bundler>=1.16:sysutils/rubygem-bundler

USES=		sqlite
USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	jcs
GH_TAGNAME=	549f66466ca753ee2f3c007b6e242d59dae05fdd

NO_ARCH=	yes
NO_BUILD=	yes

USE_RC_SUBR=	rubywarden-api
SUB_FILES=	pkg-message
SUB_LIST+=	RUBY_WITH_SUFFIX="${RUBY_WITH_SUFFIX}"

do-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR})

.include <bsd.port.mk>
