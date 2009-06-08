# New ports collection makefile for:	isomd5sum
# Date created:				June 17, 2008
# Whom:					Marzhan Mykola <delgod@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	isomd5sum
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://fedorahosted.org/releases/i/s/isomd5sum/

MAINTAINER=	delgod@portaone.com
COMMENT=	Implanting and checking checksums within an ISO9660 image

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes

MAN1=	implantisomd5.1 checkisomd5.1

MAKE_ENV+=	PYTHONPREFIX_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR} PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR}

.include <bsd.port.mk>
