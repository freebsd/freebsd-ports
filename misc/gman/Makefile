# ex:ts=8
# New ports collection makefile for:	gman
# Date created:			Mar 30, 3001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gman
PORTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/g/gman
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCHFILES=	${PORTNAME}_${PORTVERSION}-1.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A user-friendly graphical front end for the man system

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	ghostview:${PORTSDIR}/print/ghostview

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_GMAKE=	yes

MAN1=	gman.1x

post-patch:
	@${REINPLACE_CMD} -e 's,^CXX =,#CXX =,g' \
		-e 's,^CXXFLAGS =,CXXFLAGS+=,g' \
		-e 's,gtk-config,${GTK_CONFIG},g' \
		-e 's,= /usr,= ${PREFIX},g' \
		-e 's,\-O2,,g' \
		-e 's,\-lgtk \-lgdk \-lpthread ,`${GTK_CONFIG} \-\-libs gthread` ,g' ${WRKSRC}/Makefile 

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gman ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gman.pl ${PREFIX}/bin/gman.cgi
	@${MKDIR} ${PREFIX}/www/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/gman.pl ${PREFIX}/www/cgi-bin
	${INSTALL_MAN} ${WRKSRC}/gman.1x ${MANPREFIX}/man/man1

.include <bsd.port.mk>
