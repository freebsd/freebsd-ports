# New ports collection makefile for:	dv2jpg
# Date created:				24 February 2003
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dv2jpg
PORTVERSION=	1.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Type-2 DV codec-encoded AVI streams to mjpeg-encoded AVI

LIB_DEPENDS=	dv.3:${PORTSDIR}/multimedia/libdv

MAKEFILE=	makefile
USE_GNOMENG=	yes
USE_GNOME=	glib12 gtk12 gdkpixbuf

DOCS=	README.avilib	README.dv2jpg.html

post-extract:
	${RM} ${WRKSRC}/avijoin ${WRKSRC}/dv2jpg ${WRKSRC}/*.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/avijoin ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/dv2jpg ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
