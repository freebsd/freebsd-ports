# New ports collection makefile for:	openbox-themes
# Date created:				2005-12-23
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openbox-themes
PORTVERSION=	1.0.1
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	novel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Themes for Openbox

RUN_DEPENDS=	openbox:${PORTSDIR}/x11-wm/openbox

NO_BUILD=	yes
WRKSRC=		${PORTNAME}-${PORTVERSION}

do-install:
	@for i in `${LS} ${WRKDIR}/${WRKSRC}`; do \
		${CP} -r ${WRKDIR}/${WRKSRC}/$$i ${PREFIX}/share/themes/; \
	done

.include <bsd.port.mk>
