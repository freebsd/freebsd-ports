# New ports collection makefile for:	py-posix1e
# Date created:		2 January 2003
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	posix1e
PORTVERSION=	0.2.1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pylibacl
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylibacl-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python module for manipulating POSIX.1e ACLs

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e \
		's,/usr/share/doc/pylibacl,${PREFIX}/share/doc/py-posix1e,g' \
		${WRKSRC}/setup.py
.if ${OSVERSION} >= 500038
	${REINPLACE_CMD} -e 's,^.*libs.append.*posix1e.*$$,,g' \
		${WRKSRC}/setup.py
.endif

.include <bsd.port.post.mk>
