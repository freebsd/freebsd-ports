# ports collection makefile for:	malsync
# Date created:			Tue Feb 22 00:06:07 CET 2000
# Whom:				Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	malsync
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	http://www.tomw.org/malsync/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dirk
DISTNAME=	malsync_2.1.0.src

MAINTAINER=	dirk@FreeBSD.org
COMMENT=	Sync to Mobile Application Link (MAL) compliant servers

LIB_DEPENDS=	pisock.8:${PORTSDIR}/palm/pilot-link

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
WRKSRC=		${WRKDIR}/malsync

pre-patch:
	@${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/mal/client/unix/MAL31DBConfig.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/malsync ${PREFIX}/bin

.include <bsd.port.mk>
