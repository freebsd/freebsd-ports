# New ports collection makefile for: mmpython
# Date created:		09 Aug 2003
# Whom:			larse@isi.edu
#
# $FreeBSD$
#

PORTNAME=	mmpython
PORTVERSION=	0.4
CATEGORIES=	multimedia python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
# The mmpython folks keep changing their release naming scheme.
#DISTNAME=	mmpython_${PORTVERSION:C/\./-/}

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Retrieves metadata from mp3, ogg, avi, jpg and other formats

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread

# The mmpython folks keep changing their release naming scheme.
#WRKSRC=		${WRKDIR}/${PORTNAME}

# The mmpython folks keep changing their release archiver.
#USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
