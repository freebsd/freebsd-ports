# New ports collection makefile for:	py-apolicy
# Date created:				24 November 2008
# Whom:	      				Chifeng QU <chifeng@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	apolicy
PORTVERSION=	0.73
CATEGORIES=	mail python
MASTER_SITES=	http://download.gna.org/apolicy/%SUBDIR%/ \
		http://www.chifeng.name/dist/apolicy/%SUBDIR%/ \

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER?=	chifeng@gmail.com
COMMENT=	An ACL system for Postfix, as a policy daemon

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/spf.py:${PORTSDIR}/mail/py-spf \
		${PYTHON_SITELIBDIR}/IPy.py:${PORTSDIR}/net-mgmt/py-ipy

USE_PYTHON=	2.4+
USE_PYDISTUTILS=yes
USE_TWISTED=	yes
NO_BUILD=	yes
USE_RC_SUBR=	apolicyd

SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		PYTHON_CMD=${PYTHON_CMD}
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} 's|/etc|${PREFIX}/etc|' ${WRKSRC}/setup.py

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
