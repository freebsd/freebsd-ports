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

MAINTAINER=	perky@FreeBSD.org

LIB_DEPENDS=	adns.1:${PORTSDIR}/net/adns

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}

post-patch:
	@${PERL} -pi -e 's|^(include_dirs = ).*$$|\1\["${LOCALBASE}/include"\]|g; \
		s|^(library_dirs = ).*$$|\1\["${LOCALBASE}/lib"\]|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
