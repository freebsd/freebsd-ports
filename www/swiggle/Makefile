# New ports collection Makefile for: 	swiggle
# Date created:				19 Feb 2003
# Whom:					Josef El-Rayes <j.el-rayes@daemon.li>
#
# $FreeBSD$

PORTNAME=	swiggle
PORTVERSION=	0.3.3
CATEGORIES=	www
MASTER_SITES=	http://homepage.univie.ac.at/l.ertl/swiggle/files/ \
		http://www.daemon.li/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Swiggle is a commandline web image gallery generator

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg:install \
		exif.10:${PORTSDIR}/graphics/libexif:install

USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swiggle ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
