# New ports collection makefile for:	qscanplot
# Date created:				9 January 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qscanplot
PORTVERSION=	0.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lib3ds

MAINTAINER=	sobomax@FreeBSD.org

USE_X_PREFIX=	yes
USE_QT_VER=	2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-lm ${PTHREAD_LIBS}" \
		QTDIR=${X11BASE}

.include <bsd.port.mk>
