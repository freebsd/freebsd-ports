# New ports collection makefile for:	libuninameslist
# Date created:				3 November 2003
# Whom:					KANOU Hiroki <kanou@khdd.net>
#
# $FreeBSD$
#

PORTNAME=	libuninameslist
PORTVERSION=	20060907
CATEGORIES=	textproc
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_src-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library of Unicode annotation data

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	gnometarget
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
ALL_TARGET=	both
USE_LDCONFIG=	yes

.include <bsd.port.mk>
