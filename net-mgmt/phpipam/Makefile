# Created by: Jake Smith <jake@xz.cx>
# $FreeBSD$

PORTNAME=	phpipam
PORTVERSION=	1.4.1
CATEGORIES=	net-mgmt

MAINTAINER=	jake@xz.cx
COMMENT=	PHP IP Address Management IPv4/IPv6

USE_GITHUB=	yes
GH_TAGNAME=	e569141

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/share/pear/System.php:devel/pear@${PHP_FLAVOR}

NO_BUILD=	yes
NO_ARCH=	yes

CFGFILE=	config.php

SUB_FILES=	pkg-message
SUB_LIST=	DISTNAME=${DISTNAME}

OPTIONS_DEFINE=	LDAP

USES=		gettext php:web tar:
USE_PHP=	filter gettext gmp json mbstring openssl \
		pcntl pdo pdo_mysql session simplexml sockets
LDAP_USE=	PHP=ldap

pre-install:
	@if [ -f ${WRKSRC}/${CFGFILE} ]; then \
	${MV} ${WRKSRC}/${CFGFILE} ${WRKSRC}/${CFGFILE}.sample ; \
	fi

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} \
		"! -name *.orig")

.include <bsd.port.mk>
