# New ports collection makefile for:	pcbsd-role-server
#
# $FreeBSD$
#

PORTNAME=	pcbsd-role-server
PORTVERSION=	1416842024
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	joshms@pcbsd.org
COMMENT=	Includes server management software

RUN_DEPENDS=	apache24>=0:${PORTSDIR}/www/apache24 \
		nginx>=0:${PORTSDIR}/www/nginx \
		boa>=0:${PORTSDIR}/www/boa \
		tomcat8>=0:${PORTSDIR}/www/tomcat8

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
