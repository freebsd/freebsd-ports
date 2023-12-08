PORTNAME=	login_info
DISTVERSION=	1.5.1
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Roundcube login info plugin
WWW=		https://github.com/marneu/login_info/README.md

LICENSE=	GPLv2

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.0:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors
IGNORE_WITH_PHP=	83

WWWDIR=		${LOCALBASE}/www/roundcube
NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	marneu
GH_TAGNAME=	b4e8a29

#WRKSRC=		${WRKDIR}/login_info

PLUGDIR=	${WWWDIR}/plugins/login_info
PLIST_SUB+=	PLUGDIR="www/roundcube/plugins/login_info"

do-install:
	@${ECHO} "Installing in ${PLUGDIR}"
	${MKDIR} ${STAGEDIR}/${PLUGDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${PLUGDIR}

.include <bsd.port.mk>
