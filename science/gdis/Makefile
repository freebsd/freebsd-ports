# ex:ts=8
# Ports collection Makefile for:	gdis
# Date created:			Mar 3, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gdis
PORTVERSION=	0.73.3
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.seul.org/pub/gdis/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtkextra:${PORTSDIR}/x11-toolkits/gtkextra \
		gtkgl:${PORTSDIR}/x11-toolkits/gtkglarea

USE_GTK=	yes
USE_MESA=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
ALL_TARGET=	# empty

post-patch:
	@${PERL} -pi -e "s,^CC,#CC,g ; s,^CFLAGS,#CFLAGS,g ; \
		s,gtk-config,${GTK_CONFIG},g" ${WRKSRC}/Makefile
	@${PERL} -pi -e "s,%%DATADIR%%,${DATADIR},g" ${WRKSRC}/gdis.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdis ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gdis.lib ${DATADIR}

.include <bsd.port.mk>
