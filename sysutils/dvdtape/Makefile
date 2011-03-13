# New ports collection makefile for:	dvdtape
# Date created:		03 Apr 2001
# Whom:			brian
#
# $FreeBSD$
#

PORTNAME=	dvdtape
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.Awfulhak.org/pub/dvdtape/ \
		http://people.FreeBSD.org/~brian/dvdtape/ \

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create DVD master filesystems on DLT media

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		dvdtape.1
PLIST_FILES=	bin/dvdtape

.include <bsd.port.mk>
