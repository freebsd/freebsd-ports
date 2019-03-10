# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rubywarden
DISTVERSION=	0.0.0.20190207
CATEGORIES=	     security www

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Ruby implementation of the BitWarden API

LICENSE=	ISCL

RUN_DEPENDS=	rubygem-bundler>=1.16:sysutils/rubygem-bundler

USES=		sqlite
USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	jcs
GH_TAGNAME=	5ba9f9821971942d082e327edcf7f02e8ad4c4a7

NO_ARCH=	yes
NO_BUILD=	yes

USE_RC_SUBR=	rubywarden-api
SUB_FILES=	pkg-message
SUB_LIST+=	RUBY_WITH_SUFFIX="${RUBY_WITH_SUFFIX}"

do-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR})

.include <bsd.port.mk>

