# New ports collection makefile for:	wmcalc
# Date created:				28 March 2000
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmcalc
PORTVERSION=	0.3
CATEGORIES=	math windowmaker
MASTER_SITES=	http://members.cox.net/ehf_dockapps/wmcalc/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= jedgar

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Simple dockable calculator

ALL_TARGET=	clean wmcalc
PLIST_FILES=	bin/wmcalc
USE_X_PREFIX=   yes
USE_XPM=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmcalc ${PREFIX}/bin

.include <bsd.port.mk>
