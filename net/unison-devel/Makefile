# New ports collection makefile for: unison
# Date created:		4 October 2000
# Whom:			Dan Pelleg <dpelleg+unison@cs.cmu.edu>
#
# $FreeBSD$
#

PORTNAME=	unison
PORTVERSION=	2.9.20
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/beta-test/unison-${PORTVERSION}/
DISTNAME=	src
DIST_SUBDIR=	unison-${PORTVERSION}

MAINTAINER=	daniel+unison@pelleg.org

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes
MAKE_ARGS=	UISTYLE=text CFLAGS=""

post-install:
	strip ${PREFIX}/bin/unison

.include <bsd.port.mk>
