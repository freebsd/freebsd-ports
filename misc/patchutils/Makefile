# ex:ts=8
# New ports collection makefile for:	patchutils
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	patchutils
PORTVERSION=	0.1.1
CATEGORIES=	misc
MASTER_SITES=	http://people.redhat.com/twaugh/ftp/patchutils/devel/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

MAN1=	filterdiff.1 interdiff.1

.include <bsd.port.mk>
