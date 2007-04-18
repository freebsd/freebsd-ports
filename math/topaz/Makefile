# New ports collection makefile for:	topaz
# Date created:				29 July 1997
# Whom:					Issei Suzuki <issei@jp.FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	topaz
PORTVERSION=	3.40
CATEGORIES=	math
MASTER_SITES=	http://hp.vector.co.jp/authors/VA007663/topaz/bin/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A command driven graph plotting system for scientists and engineers

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XLIB=	yes
MAKEFILE=	Makefile.freebsd

post-install:
	${LN} -sf ${PREFIX}/lib/topaz/topaz.sh ${PREFIX}/bin/topaz

.include <bsd.port.mk>
