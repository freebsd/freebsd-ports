# ex:ts=8
# New ports collection makefile for:	patchutils
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	patchutils
PORTVERSION=	0.2.13
CATEGORIES=	misc
MASTER_SITES=	http://cyberelk.net/tim/data/patchutils/stable/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

MAN1=	combinediff.1 editdiff.1 filterdiff.1 fixcvsdiff.1 grepdiff.1 \
	interdiff.1 lsdiff.1 rediff.1 splitdiff.1

.include <bsd.port.mk>
