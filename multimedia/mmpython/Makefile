# New ports collection makefile for: mmpython
# Date created:		09 Aug 2003
# Whom:			larse@isi.edu
#
# $FreeBSD$
#

PORTNAME=	mmpython
PORTVERSION=	0.2
CATEGORIES=	multimedia python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mmpython_${PORTVERSION:C/\./-/}

MAINTAINER=	larse@isi.edu
COMMENT=	Retrieves metadata from mp3, ogg, avi, jpg and other formats

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
