# ex:ts=8
# New ports collection makefile for:	rascal
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rascal
PORTVERSION=	0.3.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Rascal, the Advanced Scientific CALculator

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_BISON=	yes
USE_GNOME=	yes
WRKSRC=		${WRKDIR}/Rascal-${PORTVERSION}
USE_GMAKE=	yes
ALL_TARGET=	rascal grascal

MANCOMPRESSED=	yes
MAN1=	rascal.1

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g ; \
		s,g\+\+,${CXX},g ; \
		s,doc/,share/doc/,g ; \
		s,gnome-config,${GNOME_CONFIG},g ; \
		s,CC,CXX,g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
