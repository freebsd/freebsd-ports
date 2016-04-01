# $FreeBSD$

PORTNAME=	pssh
PORTVERSION=	2.3.1
CATEGORIES=	security net sysutils
MASTER_SITES=	GOOGLE_CODE \
		LOCAL/brooks

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Parallel versions of the openssh tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rsync:net/rsync

USES=		python
USE_PYTHON=	autoplist distutils

PROJECTHOST=	parallel-ssh

.include <bsd.port.mk>
