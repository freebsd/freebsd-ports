# ex:ts=8
# Ports collection Makefile for:	bblimage
# Date created:			Jul 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bblimage
PORTVERSION=	0.66
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.uphs.upenn.edu/bbl/software/files/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of software tools for medical image processing

LIB_DEPENDS=	Xm.2:${PORTSDIR}/x11-toolkits/lesstif

USE_PYTHON=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lapack --with-python
USE_GMAKE=	yes

MAN1=	anonbblanz.1 bblimage.1 binnseg.1 conseg.1 decomment.1 dumpbblanz.1 \
	imstack.1 inleav2.1 lovar.1 qdv.1 rpsamp.1 skmiv.1 swab.1 usb2uc.1 \
	vibihist.1 vihist.1
MAN5=	cdata.5 mri_data.5 param.5

post-patch:
	@${REINPLACE_CMD} -e "s|python1\.5|${PYTHON_VERSION}|g" ${WRKSRC}/configure ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
