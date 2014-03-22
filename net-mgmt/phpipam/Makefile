# Created by: Jake Smith <jake@xz.cx>
# $FreeBSD$

PORTNAME=	phpipam
PORTVERSION=	1.0
CATEGORIES=	net-mgmt
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tar

MAINTAINER=	jake@xz.cx
COMMENT=	PHP IP Address Management IPv4/IPv6

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/share/pear/System.php:${PORTSDIR}/devel/pear

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

CFGFILE=	config.php

SUB_FILES=	pkg-message
SUB_LIST=	DISTNAME=${DISTNAME}

OPTIONS_DEFINE=	LDAP

USE_PHP=	ctype gettext gmp json mysqli pcntl session simplexml
LDAP_USE=	PHP=ldap
WANT_PHP_WEB=	yes

pre-install:
	@if [ -f ${WRKSRC}/${CFGFILE} ]; then \
	${MV} ${WRKSRC}/${CFGFILE} ${WRKSRC}/${CFGFILE}.sample ; \
	fi

do-install:
	cd ${WRKSRC} ; \
	for src in $$( ${FIND} . ! -name '*.orig') ; do \
		dst=${STAGEDIR}${WWWDIR}$${src#.} ; \
		if ${TEST} -d "$$src" ; then \
			${MKDIR} "$$dst" ; \
		else \
			${INSTALL_DATA} "$$src" "$$dst" ; \
		fi \
	done

.include <bsd.port.mk>
