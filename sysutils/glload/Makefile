# New ports collection makefile for:	glload
# Date created:			04 Dec 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glload
PORTVERSION=	0.4.0
CATEGORIES=	sysutils
MASTER_SITES=	http://glload.netpedia.net/source/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vanilla

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Gl base load monitor

PLIST_FILES=	bin/glload
USE_X_PREFIX=	yes
USE_MESA=	yes
MAKEFILE=	Makefile.FreeBSD
ALL_TARGET=	glload
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/glload ${PREFIX}/bin

.include <bsd.port.mk>
