# New ports collection makefile for:	rname
# Date created:		26 October 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rname
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://devel.ringlet.net/sysutils/rname/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Execute a program with a fake name

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes

.if 		!defined(NOPORTDOCS)
INSTALL_TARGET=	install install-doc
.endif

.include <bsd.port.mk>
