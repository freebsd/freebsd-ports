PORTNAME=	automatic_addressbook
PORTVERSION=	0.4.3
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	andrej@ebert.su
COMMENT=	Roundcube webmail automatic addressbook plugin

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=0.8:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors
IGNORE_WITH_PHP=80
USE_GITHUB=	yes
GH_ACCOUNT=	sblaisot

NO_BUILD=	yes
NO_ARCH=	yes

RCDIR=		${PREFIX}/www/roundcube
WWWDIR=		${RCDIR}/plugins/automatic_addressbook

SUB_FILES=	pkg-message
SUB_LIST=	RCDIR=${RCDIR} PLUGINDIR=${WWWDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
