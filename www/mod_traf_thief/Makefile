# New ports collection makefile for:	mod_traf_thief
# Date created:				Sun Oct  5
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_traf_thief
PORTVERSION=	0.01
CATEGORIES=	www
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/
EXTRACT_SUFX=	.c
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows you to redirect part of the traffic to your url

MAKE_JOBS_SAFE=  yes

DEPRECATED=	will be unsupported by ASF when 2.4.0 is release, migrate to 2.2.x+ now
EXPIRATION_DATE=	2011-05-01

USE_APACHE=	2.0
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

RESTRICTED=	No licence
NO_WRKSUBDIR=	YES

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKDIR}/${PORTNAME}.c

.include <bsd.port.mk>
