# New ports collection makefile for:	kmess
# Date created:			21 June 2002
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	kmess
PORTVERSION=	1.3
PORTREVISION=	4
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MSN Messenger Client for KDE3

LIB_DEPENDS=	mimelib.1:${PORTSDIR}/deskutils/kdepim3

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

pre-patch:
	${REINPLACE_CMD} -e '23s/^$$/#include <unistd.h>/' \
		${WRKSRC}/kmess/kmessview.cpp
	${REINPLACE_CMD} -e '20s/^$$/#include <ctype.h>/' \
		${WRKSRC}/kmess/network/mimemessage.h
	${REINPLACE_CMD} -e '35s|^$$|#include <netinet/in.h>|' \
		${WRKSRC}/kmess/network/msnconnection.h
	${REINPLACE_CMD} -e 's/-pedantic //g; s/-O2//g; \
		s/-lpthread/${PTHREAD_LIBS}/g' ${WRKSRC}/configure

.include <bsd.port.mk>
