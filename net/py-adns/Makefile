# New ports collection makefile for:	py-adns
# Date created:		24 February 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	adns
PORTVERSION=	1.0.0
CATEGORIES=	net python
MASTER_SITES=	http://dustman.net/andy/python/adns-python/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	adns-python-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

LIB_DEPENDS=	adns.1:${PORTSDIR}/net/adns

USE_PYTHON=	yes
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

post-patch:
	@${PERL} -pi -e 's|^(include_dirs = ).*$$|\1\["${LOCALBASE}/include"\]|g; \
		s|^(library_dirs = ).*$$|\1\["${LOCALBASE}/lib"\]|g' \
		${WRKSRC}/setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
