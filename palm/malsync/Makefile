# ports collection makefile for:	malsync
# Version required:		1.8
# Date created:			Tue Feb 22 00:06:07 CET 2000
# Whom:				Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	malsync_src_1_8
PKGNAME=	malsync-1.8
CATEGORIES=	palm
MASTER_SITES=	http://www.tomw.org/ \
		http://people.FreeBSD.org/~dirk/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.org

LIB_DEPENDS=	pisock.3:${PORTSDIR}/palm/pilot-link

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/malsync_src/mal/client/unix
FETCH_BEFORE_ARGS=	-b

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/malsync ${PREFIX}/bin

.include <bsd.port.mk>
