# ex:ts=8
# Ports collection makefile for:	Python OpenSSL Wrappers
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pow
PORTVERSION=	0.6.1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Python OpenSSL Wrappers

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_OPENSSL=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/POW.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
