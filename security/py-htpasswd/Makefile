# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	htpasswd
PORTVERSION=	2008.03.05
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	http://files.bsdroot.lv/my/FreeBSD/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	graudeejs@gmail.com
COMMENT=	Replacement for htpasswd

USE_PYTHON=	yes
USE_XZ=		yes

PLIST_FILES=	bin/${PORTNAME}.py

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

NO_STAGE=	yes
post-patch:
	${SED} -I.orig -e 's|^#!/usr/bin/python|#!/usr/bin/env python|' ${WRKDIR}/${PORTNAME}.py

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.py ${PREFIX}/bin/

.include <bsd.port.mk>
