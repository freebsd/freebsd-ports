PORTNAME=	veximaccountadmin
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://axel.sjostedt.no/misc/files/
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	rcube_plg_veximaccountadmin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Roundcube vexim account admin plugin

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=0.9:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors
IGNORE_WITH_PHP=	81 82

WWWDIR=		${PREFIX}/www/roundcube
REINPLACE_ARGS=	-i ''
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/veximaccountadmin

PLIST_SUB+=	PLUGINDIR="${PLUGINDIR}"
PLUGINDIR=	${WWWDIR}/plugins/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's/new rcube_mdb2/new rcube_db/g' ${WRKSRC}/veximaccountadmin.php

do-install:
	@${ECHO} "Installing in ${PLUGINDIR}"
	${MKDIR} ${STAGEDIR}/${PLUGINDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${PLUGINDIR}

.include <bsd.port.mk>
