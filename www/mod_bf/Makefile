# New ports collection makefile for:	mod_bf
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_bf
PORTVERSION=	0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	modbf

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A brainf*ck module for Apache

USE_APACHE=	yes

do-build:
	@cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/mod_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
