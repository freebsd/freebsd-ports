# ex:ts=8
# Ports collection makefile for:	catdvi
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	catdvi
PORTVERSION=	0.12
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
MAKEFILE=	GNUmakefile
USE_GMAKE=	yes
ALL_TARGET=	# empty

MAN1=	catdvi.1

post-patch:
	${GREP} -lR "malloc.h" ${WRKSRC} | xargs \
	  ${PERL} -pi -e "s/malloc.h/stdlib.h/g"

.include <bsd.port.mk>
