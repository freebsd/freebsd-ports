# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	bft
PORTVERSION=	1.1.5
CATEGORIES=	science parallel
MASTER_SITES=	http://research.edf.com/fichiers/fckeditor/Commun/Innovation/logiciels/code_saturne/Releases/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Base Functions and Types library

LICENSE=	LGPL21

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		zip
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
