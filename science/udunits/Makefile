# New ports collection makefile for:	udunits
# Date created:		31 December 2004
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	udunits
PORTVERSION=	1.12.4
CATEGORIES=	science math
MASTER_SITES=	ftp://unidata.ucar.edu/pub/${PORTNAME}/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	A library for manipulating units of physical quantities

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes

CFLAGS+=	-fPIC

MAN1=		udunits.1 \
		udunitsperl.1
MAN3=		udunits.3 \
		udunits.3f

post-build:
	${REINPLACE_CMD} -e 's: doc_[^_]*_install::' \
		-e 's: doc_install::' \
		"${WRKSRC}/perl/Makefile"

.include <bsd.port.mk>
