# $FreeBSD$

PORTNAME=	pssh
PORTVERSION=	2.3.1
CATEGORIES=	security net sysutils
MASTER_SITES=	GOOGLE_CODE \
		LOCAL/brooks

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Parallel versions of the openssh tools

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PROJECTHOST=	parallel-ssh

.include <bsd.port.mk>
