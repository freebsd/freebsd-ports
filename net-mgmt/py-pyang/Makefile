# New ports collection makefile for:	py-pyang
# Date created:			2009-07-05
# Whom:				Bruce Simpson
#
# $FreeBSD$
#

PORTNAME=	pyang
PORTVERSION=	0.9.3
CATEGORIES=	net-mgmt python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Validator and code generator for YANG (RFC 4741)

USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes

MAKE_ENV+=	YANG_INSTALL=${PREFIX}

MAN1=		pyang.1
MANCOMPRESSED=	no

do-patch:
	@${REINPLACE_CMD} 's,share/man/man1,man/man1,' ${WRKSRC}/setup.py

# TODO: Sed YANG_INSTALL into pyang itself.
# TODO: Add yang2html to package.

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "Don't forget to set YANG_INSTALL to ${PREFIX} in your environment."
	@${ECHO_MSG}

.include <bsd.port.mk>
