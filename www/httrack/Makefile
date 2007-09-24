# New ports collection makefile for:	httrack
# Date created:		Sun Jun 17 10:28:52 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httrack
PORTVERSION=	3.41.3
CATEGORIES=	www
MASTER_SITES=	http://www.httrack.com/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Easy-to-use offline browser utility and website copier

WRKSRC=		${WRKDIR}/${PORTNAME}-3.41.22

USE_GNOME=	gnometarget
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

MAN1=		htsserver.1 httrack.1 proxytrack.1 webhttrack.1

post-patch:
	@${REINPLACE_CMD} -e 's|>&6,|>\&6|g ; \
		 s|-O -g3 ||g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
