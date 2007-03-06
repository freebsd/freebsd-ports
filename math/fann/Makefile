# New ports collection makefile for:	fann
# Date created:		2007-03-04
# Whom:			Tz-Huan Huang <tzhuan@csie.org>
#
# $FreeBSD$
#

PORTNAME=	fann
PORTVERSION=	2.1.0b
CATEGORIES=	math science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fann
DISTNAME=	fann-2.1.0beta

MAINTAINER=	tzhuan@csie.org
COMMENT=	A free open source neural network library

WRKSRC=		${WRKDIR}/fann-2.1.0
USE_ZIP=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
