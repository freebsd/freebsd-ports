# New ports collection makefile for:	kmess
# Date created:			21 June 2002
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	kmess
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	perky@FreeBSD.org

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's/rightButtonClicked/contextMenuRequested/g' \
		${WRKSRC}/kmess/kmessviewinterface.cpp

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
