# New ports collection makefile for:	mod_log_data
# Date created:				Sun Oct  5
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_log_data
PORTVERSION=	0.0.3
CATEGORIES=	www
MASTER_SITES=	http://loghttp.sourceforge.net/files/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Module for Apache 2.0 which logs incoming and outgoing data

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache2
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_APACHE=	YES
WITH_APACHE2=	YES

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386

do-build:
	@(cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -A -i ${PORTNAME}.la)

.include <bsd.port.post.mk>
