# New ports collection makefile for: mmpython
# Date created:		09 Aug 2003
# Whom:			larse@isi.edu
#
# $FreeBSD$
#

PORTNAME=	mmpython
PORTVERSION=	0.4.8
CATEGORIES=	multimedia python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lewiz@compsoc.man.ac.uk
COMMENT=	Retrieves metadata from mp3, ogg, avi, jpg and other formats

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread
RUN_DEPENDS=	lsdvd:${PORTSDIR}/multimedia/lsdvd

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's,/usr/local/,${LOCALBASE}/,g' \
		-e 's|gcc -ldvdread|gcc -L${LOCALBASE}/lib -ldvdread|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
