# New ports collection makefile for:	qtfw
# Date created:				Sat Aug 25 10:42:02 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	qtfw
PORTVERSION=	0.5
PORTREVISION=	7
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GUI frontend for ipfw utility in FreeBSD

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}
USE_GMAKE=	yes
USE_QT_VER=	3
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_FILES=	bin/qtfw

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/qtfw ${PREFIX}/bin

.include <bsd.port.mk>
