PORTNAME=	login_info
DISTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	https://www.std-soft.de/webmail/plugins/
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}_rc0.5_v${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Roundcube login info plugin

LICENSE=	GPLv2

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=0.5:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors
IGNORE_WITH_PHP=	81 82

WWWDIR=		${LOCALBASE}/www/roundcube
NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/login_info

PLUGDIR=	${WWWDIR}/plugins/login_info
PLIST_SUB+=	PLUGDIR="www/roundcube/plugins/login_info"

do-install:
	@${ECHO} "Installing in ${PLUGDIR}"
	${MKDIR} ${STAGEDIR}/${PLUGDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${PLUGDIR}

.include <bsd.port.mk>
