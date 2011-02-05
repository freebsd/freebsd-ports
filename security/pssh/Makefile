# Ports collection makefile for:	pssh
# Date created:				Mon Jul 2, 2007
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pssh
PORTVERSION=	2.1.1
CATEGORIES=	security net sysutils
MASTER_SITES=	GOOGLE_CODE \
		LOACL/brooks

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Parallel versions of the openssh tools

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USE_PYTHON=	YES
USE_PYDISTUTILS=easy_install

PROJECTHOST=	parallel-ssh

.include <bsd.port.mk>
