# New ports collection makefile for:	py-pyrad
# Date created:				13 August 2007
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyrad
PORTVERSION=	0.9
CATEGORIES=	net python
MASTER_SITES=	http://www.wiggy.net/files/ \
		http://www.sourcefiles.org/Networking/Tools/Authentication/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python implementation of RADIUS client

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyrad

.if !defined(NOPORTEXAMPLES)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/example -cf- . | ${TAR} -C ${EXAMPLESDIR} -xpf-
.endif

.include <bsd.port.mk>
