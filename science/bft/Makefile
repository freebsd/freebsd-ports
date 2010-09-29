# New ports collection makefile for:	bft
# Date created:		Sun 1 apr 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	bft
PORTVERSION=	1.0.8
CATEGORIES=	science parallel
MASTER_SITES=	http://research.edf.com/fichiers/fckeditor/Commun/Innovation/logiciels/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Base Functions and Types library

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

TESTSBIN=	bft_test bft_mem_usage_test bft_printf_test

pre-configure:
	# No useful doc there
	${REINPLACE_CMD} -e 's|tests doc|tests|' ${WRKSRC}/Makefile.in

regression-test:
.for pg in ${TESTSBIN}
	(cd ${WRKSRC}/tests; ./${pg} arg1 arg2)
.endfor

.include <bsd.port.mk>
