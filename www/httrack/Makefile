# New ports collection makefile for:	httrack
# Date created:		Sun Jun 17 10:28:52 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httrack
PORTVERSION=	3.32.03
CATEGORIES=	www
MASTER_SITES=	http://httrack.free.fr/mirror/ \
		http://www.httrack.com/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy-to-use offline browser utility and website copier

BROKEN=		Size mismatch

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gnometarget
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		htsserver.1 httrack.1 webhttrack.1

post-patch:
	@${REINPLACE_CMD} -e 's|>&6,|>\&6|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
