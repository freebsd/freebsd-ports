# New ports collection makefile for:	npadmin
# Date created:		13 Nov 1998
# Whom:			Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	npadmin
PORTVERSION=	0.8.7
CATEGORIES=	sysutils print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dom@happygiraffe.net

MAN1=		npadmin.1

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
