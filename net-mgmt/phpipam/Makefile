# New ports collection makefile for: 	phpipam
# Date created:				10 June 2012
# Whom:					Jake Smith <jake@xz.cx>
#
# $FreeBSD$
#

PORTNAME=	phpipam
PORTVERSION=	0.7
CATEGORIES=	net-mgmt
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tar

MAINTAINER=	jake@xz.cx
COMMENT=	PHPIPAM: PHP IP Address Management IPv4/IPv6

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/share/pear/System.php:${PORTSDIR}/devel/pear

FETCH_ARGS=	-Fpr

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

CFGFILE=	config.php

SUB_FILES=	pkg-message
SUB_LIST=	DISTNAME=${DISTNAME}

OPTIONS_DEFINE=	LDAP

USE_MYSQL=	yes
USE_PHP=	ctype mysqli session gmp
WANT_PHP_WEB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

.include <bsd.port.pre.mk>

pre-install:
	@${MV} ${WRKSRC}/${CFGFILE} ${WRKSRC}/${CFGFILE}.sample

do-install:
	cd ${WRKSRC} ; \
	for src in $$( ${FIND} . ! -name '*.orig') ; do \
		dst=${WWWDIR}$${src#.} ; \
		if ${TEST} -d "$$src" ; then \
			${MKDIR} "$$dst" ; \
		else \
			${INSTALL_DATA} -o root -g wheel "$$src" "$$dst" ; \
		fi \
	done

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
