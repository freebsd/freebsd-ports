PORTNAME=	phpipam
DISTVERSION=	1.5.2
CATEGORIES=	net-mgmt

MAINTAINER=	jake@xz.cx
COMMENT=	PHP IP Address Management IPv4/IPv6
WWW=		https://phpipam.net/

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/share/pear/System.php:devel/pear@${PHP_FLAVOR}

USES=		cpe gettext php:web tar:
IGNORE_WITH_PHP=	82 83

USE_GITHUB=	yes
GH_TAGNAME=	be8a2c4

USE_PHP=	ctype curl dom filter gd gettext gmp iconv mbstring mcrypt \
		pcntl pdo pdo_mysql posix session simplexml sockets

NO_ARCH=	yes
NO_BUILD=	yes

CFGFILE=	config.php

SUB_FILES=	pkg-message
SUB_LIST=	DISTNAME=${DISTNAME}

OPTIONS_DEFINE=	LDAP

LDAP_USE=	PHP=ldap

pre-install:
	@if [ -f ${WRKSRC}/${CFGFILE} ]; then \
	${MV} ${WRKSRC}/${CFGFILE} ${WRKSRC}/${CFGFILE}.sample ; \
	fi

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} \
		"! -name *.orig")

.include <bsd.port.mk>
