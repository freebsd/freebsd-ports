# New ports collection makefile for:	cuecat
# Date created:				18 October 2000
# Whom:					mwm@mired.org
#
# $FreeBSD$
#

PORTNAME=	cuecat
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	http://www.mired.org/downloads/ \
		http://mwm.tzo.com/downloads/

MAINTAINER=	mwm@mired.org

NO_BUILD=	yes
MAN1=		cuecat.1
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/cuecat

pre-install:
	@${MV} ${WRKSRC}/cuecat.py ${WRKSRC}/cuecat.py-orig
	@${SED} 's;/usr/opt;${PREFIX};' ${WRKSRC}/cuecat.py-orig >${WRKSRC}/cuecat.py
	@${MV} ${WRKSRC}/barcode.py ${WRKSRC}/barcode.py-orig
	@${SED} 's;/usr/opt;${PREFIX};' ${WRKSRC}/barcode.py-orig >${WRKSRC}/barcode.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cuecat.py ${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/barcode.py ${PYTHON_SITELIBDIR}
	python -O -c "import barcode, cuecat"
	${LN} -sf ${PYTHON_SITELIBDIR}/cuecat.py ${PREFIX}/bin/cuecat
	${INSTALL_MAN} ${WRKSRC}/cuecat.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
