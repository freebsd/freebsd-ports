# New ports collection makefile for:   	asterisk-fop
# Date created:                         22 Sep 2006
# Whom:                                 Marcelo Araujo <araujo@bsdmail.org>
#
# $FreeBSD$

PORTNAME=	op_panel
PORTVERSION=	0.30
CATEGORIES=	www
MASTER_SITES=	http://www.asternic.org/files/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Flash Operator Panel for the Asterisk PBX

NO_BUILD=	yes
USE_PERL5=	yes
USE_PHP=	pcre zlib session xml gd
WANT_PHP_WEB=	yes

LIB_DEPENDS+=	flash.0:${PORTSDIR}/www/flashplugin-mozilla \
		ming.4:${PORTSDIR}/graphics/p5-ming

WEBOWN?=	www
WEBGRP?=	www
APACHEDIR=	${LOCALBASE}/www
INSTALLDIR=	${APACHEDIR}/${PORTNAME}

do-install:
	${MKDIR} ${INSTALLDIR}
	cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdm -R ${WEBOWN}:${WEBGRP} ${INSTALLDIR}

.include <bsd.port.mk>
