# Ports collection Makefile for:	sudosh
# Date created:				10/28/2004
# Whom:					cy@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		sudosh
PORTVERSION=		1.4.1
PORTREVISION=		1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/}

MAINTAINER=		cy@FreeBSD.org
COMMENT=	A sudo shell

USE_BZIP2=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS=		--bindir="${PREFIX}/bin"

.include <bsd.port.mk>
