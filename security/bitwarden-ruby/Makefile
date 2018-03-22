# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bitwarden-ruby
DISTVERSION=	0.0.0.20180321
CATEGORIES=	security www

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Ruby implementation of the BitWarden API

LICENSE=	ISCL

RUN_DEPENDS=	rubygem-sinatra>=2.0:www/rubygem-sinatra \
		rubygem-sinatra-contrib>=2.0:www/rubygem-sinatra-contrib \
		rubygem-unicorn>0:www/rubygem-unicorn \
		rubygem-json>0:devel/rubygem-json \
		rubygem-pbkdf2-ruby>0:security/rubygem-pbkdf2-ruby \
		rubygem-rotp>0:devel/rubygem-rotp \
		rubygem-jwt>0:www/rubygem-jwt \
		rubygem-sqlite3>0:databases/rubygem-sqlite3 \
		rubygem-rqrcode>0:www/rubygem-rqrcode

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	jcs
GH_TAGNAME=	c3e0eb1

NO_ARCH=	yes
NO_BUILD=	yes

USE_RC_SUBR=	bitwarden-api
SUB_LIST+=	RUBY_WITH_SUFFIX="${RUBY_WITH_SUFFIX}"

do-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR})

.include <bsd.port.mk>
