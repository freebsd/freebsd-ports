PORTNAME=	veximaccountadmin
PORTVERSION=	0.1.20171224
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Roundcube vexim account admin plugin
WWW=		http://axel.sjostedt.no/misc/dev/roundcube/

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.3:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors

WWWDIR=		${PREFIX}/www/roundcube
REINPLACE_ARGS=	-i ''
NO_BUILD=	yes

PLIST_SUB+=	PLUGINDIR="${PLUGINDIR}"
PLUGINDIR=	${WWWDIR}/plugins/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	vexim
GH_PROJECT=	Roundcube-Plugin-VeximAccountAdmin
GH_TAGNAME=	3912bd9

post-patch:
	@${REINPLACE_CMD} -e 's/new rcube_mdb2/new rcube_db/g' ${WRKSRC}/veximaccountadmin.php

do-install:
	@${ECHO} "Installing in ${PLUGINDIR}"
	${MKDIR} ${STAGEDIR}/${PLUGINDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${PLUGINDIR}

.include <bsd.port.mk>
