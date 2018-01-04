# Created by: Mykola Marzhan <delgod@portaone.com>
# $FreeBSD$

PORTNAME=	isomd5sum
PORTVERSION=	1.0.11
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	delgod@portaone.com
COMMENT=	Implanting and checking checksums within an ISO9660 image

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:devel/popt

USES=		gmake python:2.7
USE_GITHUB=	yes
GH_ACCOUNT=	rhinstaller

MAKE_ENV+=	PYTHONPREFIX_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR} PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR}
MAKE_JOBS_UNSAFE= yes

.include <bsd.port.mk>
