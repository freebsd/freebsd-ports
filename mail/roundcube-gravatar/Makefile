PORTNAME=	gravatar
DISTVERSION=	1.6
DISTVERSIONPREFIX=v
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Roundcube gravatar plugin
WWW=		https://github.com/prodrigestivill/roundcube_gravatar/

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors
IGNORE_WITH_PHP=	83

WWWDIR=		${LOCALBASE}/www/roundcube
NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	prodrigestivill
GH_PROJECT=	roundcube-gravatar

PLUGDIR=	${WWWDIR}/plugins/gravatar
PLIST_SUB+=	PLUGDIR="www/roundcube/plugins/gravatar"

do-install:
	@${ECHO} "Installing in ${PLUGDIR}"
	${MKDIR} ${STAGEDIR}/${PLUGDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${PLUGDIR}

gen-plist:
	${FIND} ${WRKSRC} -type f -print | ${SORT} | \
	    ${GREP} -v '.gitignore' | \
	    ${SED} -e "s:${WRKSRC}:%%PLUGDIR%%:g" \
	           -e 's:%%PLUGDIR%%/config.inc.php.dist:@sample %%PLUGDIR%%/config.inc.php.dist %%PLUGDIR%%/config.inc.php:'  \
	    > pkg-plist.new
	${FIND} ${WRKSRC} -type d -print | ${SORT} -r | \
	    ${SED} -e "s:${WRKSRC}:@dir %%PLUGDIR%%:g"  >> pkg-plist.new

.include <bsd.port.mk>
