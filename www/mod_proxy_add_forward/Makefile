# New ports collection makefile for:	mod_proxy_add_forward
# Date created:		25 March 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mod_proxy_add_forward
PORTVERSION=	20010201
CATEGORIES=	www
MASTER_SITES=	http://develooper.com/code/mpaf/ \
		http://atreides.freenix.no/~anders/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.c

MAINTAINER=	anders@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

NO_WRKSUBDIR=	YES

APXS?=		${LOCALBASE}/sbin/apxs

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -p ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-build:
	cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	cd ${WRKSRC} && ${APXS} -A -i ${PORTNAME}.so
	@${ECHO} "================================================================================"
	@${ECHO} "Enable mod_proxy_add_forward in Apache's config manually."
	@${ECHO} "================================================================================"

.include <bsd.port.mk>
