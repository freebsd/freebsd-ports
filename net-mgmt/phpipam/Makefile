# Created by: Jake Smith <jake@xz.cx>

PORTNAME=	phpipam
PORTVERSION=	1.4.3
CATEGORIES=	net-mgmt

MAINTAINER=	jake@xz.cx
COMMENT=	PHP IP Address Management IPv4/IPv6

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/share/pear/System.php:devel/pear@${PHP_FLAVOR}

USES=		cpe gettext php:web tar:

USE_GITHUB=	yes
GH_TAGNAME=	f6302da

USE_PHP=	ctype curl filter gd gettext gmp iconv json mbstring mcrypt \
		openssl pcntl pdo pdo_mysql session simplexml sockets

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
