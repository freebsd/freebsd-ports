# ex:ts=8
# Ports collection makefile for:	catdvi
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	catdvi
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
MAKEFILE=	GNUmakefile
ALL_TARGET=	# empty

MAN1=	catdvi.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/catdvi ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/catdvi.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
