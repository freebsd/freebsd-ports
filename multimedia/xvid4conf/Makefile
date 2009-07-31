# New ports collection makefile for:	xvid4conf
# Date created:		11 June 2004
# Whom:			Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	xvid4conf
PORTVERSION=	1.12
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.nerim.net/debian-marillat/pool/main/x/xvid4conf/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lofi
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XviD configuration panel for transcode

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
