# New ports collection makefile for:	bft
# Date created:		Sun 1 apr 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	bft
PORTVERSION=	1.0.3
CATEGORIES=	science parallel
MASTER_SITES=	http://www.edf.fr/html/RetD/livraison_saturne_${REL_DATE}/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Base Functions and Types library

REL_DATE=	070305

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

TESTSBIN=	bft_test

pre-configure:
	# No useful doc there
	${REINPLACE_CMD} -e 's|tests doc|tests|' ${WRKSRC}/Makefile.in

regression-test:
.for pg in ${TESTSBIN}
	@(cd ${WRKSRC}/tests; ./${pg} arg1 arg2)
.endfor

.include <bsd.port.mk>
