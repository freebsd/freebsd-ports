# New ports collection makefile for:	py-m2crypto
# Date created:				27 March 2001
# Whom:					Peter Haight <peterh@sapros.com>
#
# $FreeBSD$
#

PORTNAME=	m2crypto
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	http://www.post1.com/home/ngps/m2/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ngps@post1.com

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13 \
		pinstall:${PORTSDIR}/devel/pinstall

WRKSRC=		${WRKDIR}/${DISTNAME}/swig
USE_PYTHON=	yes
USE_ZIP=	yes
USE_OPENSSL=	yes

PINSTALL_PLIST=	${WRKDIR}/pinstall-plist

post-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/../M2Crypto

do-install:
	${MKDIR} ${WRKDIR}/lib/${PYTHON_VERSION}/site-packages
	cd ${WRKDIR}/lib/${PYTHON_VERSION}/site-packages && ${LN} -sf ../../../${DISTNAME}/M2Crypto

post-install:
	${LOCALBASE}/bin/pinstall -v -f ${TMPPLIST} -d ${WRKDIR}

.include <bsd.port.mk>
