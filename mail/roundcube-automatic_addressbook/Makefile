PORTNAME=	automatic_addressbook
PORTVERSION=	0.4.3
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	andrej@ebert.su
COMMENT=	Roundcube webmail automatic addressbook plugin
WWW=		https://github.com/sblaisot/automatic_addressbook

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=0.8:mail/roundcube@${PHP_FLAVOR}

USES=		php:flavors
USE_GITHUB=	yes
GH_ACCOUNT=	sblaisot
IGNORE_WITH_PHP=83

WWWDIR=		${RCDIR}/plugins/automatic_addressbook
NO_ARCH=	yes
NO_BUILD=	yes

RCDIR=		${PREFIX}/www/roundcube

SUB_FILES=	pkg-message
SUB_LIST=	PLUGINDIR=${WWWDIR} \
		RCDIR=${RCDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
