# New ports collection makefile for:	xvid4conf
# Date created:		11 June 2004
# Whom:			Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	xvid4conf
PORTVERSION=	1.12
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.nerim.net/debian-marillat/pool/main/x/xvid4conf/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lofi
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

DEPRECATED=     Upstream has disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XviD configuration panel for transcode

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
