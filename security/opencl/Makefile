# ex:ts=8
# New ports collection makefile for:	opencl
# Date created:			Mar 3, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opencl
PORTVERSION=	0.7.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	OpenCL-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_NEWGCC=	yes

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.pl
CONFIGURE_ARGS=	gcc-freebsd-generic

USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

PLIST_SUB=	PORTVERSION=0.7.2

.include <bsd.port.mk>
