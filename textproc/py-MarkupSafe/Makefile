# Created by: wen@FreeBSD.org
# $FreeBSD$

PORTNAME=		MarkupSafe
PORTVERSION=		0.18
CATEGORIES=		textproc python
MASTER_SITES=		CHEESESHOP
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		wen@FreeBSD.org
COMMENT=		Implements a XML/HTML/XHTML Markup safe string for Python

LICENSE=		BSD

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	no

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
