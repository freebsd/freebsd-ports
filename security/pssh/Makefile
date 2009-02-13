# Ports collection makefile for:	pssh
# Date created:				Mon Jul 2, 2007
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pssh
PORTVERSION=	1.4.3
CATEGORIES=	security net sysutils
MASTER_SITES=	http://www.theether.org/pssh/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Parallel versions of the openssh tools

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USE_PYTHON=	YES
USE_PYDISTUTILS=easy_install

FIX_PYPATH=	bin/pnuke \
		bin/prsync \
		bin/pscp \
		bin/pslurp \
		bin/pssh

post-patch:
	${REINPLACE_CMD} -e 's|#!/usr/bin/env python|#!${PYTHON_CMD}|' \
		${FIX_PYPATH:S/^/${WRKSRC}\//}

.include <bsd.port.mk>
