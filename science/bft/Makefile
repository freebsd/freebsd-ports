# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	bft
PORTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	science parallel
MASTER_SITES=	http://research.edf.com/fichiers/fckeditor/Commun/Innovation/logiciels/code_saturne/Releases/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Base Functions and Types library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		libtool zip
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

TESTSBIN=	bft_test bft_mem_usage_test bft_printf_test

pre-configure:
	# No useful doc there
	${REINPLACE_CMD} -e 's|tests doc|tests|' ${WRKSRC}/Makefile.in

do-test:
.for pg in ${TESTSBIN}
	(cd ${WRKSRC}/tests; ./${pg} arg1 arg2)
.endfor

.include <bsd.port.mk>
