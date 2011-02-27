# New ports collection makefile for:	py-PF
# Date created:		2009-02-07
# Whom:			Sofian Brabez <sbrabez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	PF
PORTVERSION=	0.0.5
CATEGORIES=	security python
MASTER_SITES=	SF/py-${PORTNAME:L}/py-${PORTNAME:L}/${DISTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYTHON_PKGNAMEPREFIX:C/[0-9]+//}${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sbrabez@gmail.com
COMMENT=	A pure-Python module for managing OpenBSD Packet Filter

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PYTHON_PKGNAMEPREFIX:C/[0-9]+//}_${PORTNAME}

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's#"0.0.4"#"0.0.5"#g' ${WRKSRC}/setup.py

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
