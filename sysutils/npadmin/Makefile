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

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

MAN1=		npadmin.1

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	LIBS=-lgnugetopt LDFLAGS=-L${LOCALBASE}/lib CPPFLAGS=-I${LOCALBASE}/include

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

pre-configure:
	${RM} ${WRKSRC}/getopt.h ${WRKSRC}/getopt1.c

.include <bsd.port.mk>
