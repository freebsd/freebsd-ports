# New ports collection makefile for:	uwatch
# Date created:		3 November 1999
# Whom:			James Howard <ports@vocito.com>
#
# $FreeBSD$
#

PORTNAME=	uwatch
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vocito.com/downloads/software/uwatch/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monitor user logins and logouts

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAN1=		uwatch.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/uwatch

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

.include <bsd.port.post.mk>
