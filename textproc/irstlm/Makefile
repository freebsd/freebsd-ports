# New ports collection makefile for:	irstlm
# Date created:				31 May 2010
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	irstlm
PORTVERSION=	5.40.01
CATEGORIES=	textproc
MASTER_SITES=	http://hlt.fbk.eu/sites/hlt.fbk.eu/files/irstlm/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	The IRST Language Modeling Toolkit

USE_ZIP=	yes
GNU_CONFIGURE=	yes

do-install:
.for f in dict ngt compile_lm interpolate_lm prune_lm quantize_lm tlm
	${INSTALL_PROGRAM} ${WRKSRC}/src/$f ${PREFIX}/bin/
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/libirstlm.a ${PREFIX}/lib/
	${RANLIB} ${PREFIX}/lib/libirstlm.a
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${PREFIX}/include/

.include <bsd.port.mk>
