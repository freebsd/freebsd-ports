# New ports collection makefile for:	qtfw
# Date created:				Sat Aug 25 10:42:02 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	qtfw
PORTVERSION=	0.5
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GUI frontend for ipfw utility in FreeBSD

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}
USE_GMAKE=	yes
USE_QT_VER=	3
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_FILES=	bin/qtfw

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/qtfw ${PREFIX}/bin

.include <bsd.port.mk>
