# ex:ts=8
# Ports collection Makefile for:	kmovisto
# Date created:			Oct 23, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	kmovisto
PORTVERSION=	0.6.0
CATEGORIES=	science
MASTER_SITES=	http://mitglied.lycos.de/pageofmh/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A real 3-D molecule viewer

USE_REINPLACE=	yes
USE_QT_VER=	3
USE_MESA=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		-e "s|-pedantic||g" -e "s|-ldl||g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|-ldl||g" ${WRKSRC}/kmovisto/Makefile.in

.include <bsd.port.mk>
