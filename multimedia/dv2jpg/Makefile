# New ports collection makefile for:	dv2jpg
# Date created:				24 February 2003
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dv2jpg
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Type-2 DV codec-encoded AVI streams to mjpeg-encoded AVI

LIB_DEPENDS=	dv.3:${PORTSDIR}/multimedia/libdv

USE_GNOME=	gdkpixbuf
MAKEFILE=	makefile

post-extract:
	${RM} ${WRKSRC}/avijoin ${WRKSRC}/dv2jpg ${WRKSRC}/*.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/avijoin ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/dv2jpg ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in README.avilib	README.dv2jpg.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
