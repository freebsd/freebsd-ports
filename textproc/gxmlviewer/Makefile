# ex:ts=8
# New ports collection makefile for:	gxmlviewer
# Date created:			Nov 8, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gxmlviewer
PORTVERSION=	1.3.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
