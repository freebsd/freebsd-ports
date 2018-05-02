# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	veximaccountadmin
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://axel.sjostedt.no/misc/files/
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	rcube_plg_veximaccountadmin

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Roundcube vexim account admin plugin

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=0.9:mail/roundcube@${PHP_FLAVOR}

USES=	php:flavors
NO_BUILD=	yes

PLIST_SUB+=	PLUGINDIR="${PLUGINDIR}"
WWWDIR=		${PREFIX}/www/roundcube
PLUGINDIR=	${WWWDIR}/plugins/${PORTNAME}
WRKSRC=		${WRKDIR}/veximaccountadmin
REINPLACE_ARGS=-i ''

post-patch:
	@${REINPLACE_CMD} -e 's/new rcube_mdb2/new rcube_db/g' ${WRKSRC}/veximaccountadmin.php

do-install:
	@${ECHO} "Installing in ${PLUGINDIR}"
	${MKDIR} ${STAGEDIR}/${PLUGINDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${PLUGINDIR}

.include <bsd.port.mk>
