# New ports collection makefile for:	xicq
# Date created:				29 June 1998
# Whom:					scrappy
#
# $FreeBSD$
#

PORTNAME=	xicq
PORTVERSION=	19980712	
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://projekt.pinknet.cz/ftp/ICQ/linux/Xicq/
DISTNAME=	xicq-071298-snapshot.src

MAINTAINER=	scrappy@FreeBSD.org
COMMENT=	Xtropy's ICQ Client

WRKSRC=		${WRKDIR}/xicq-071298

USE_GMAKE=	yes
MAKE_ENV=	OPT="${CFLAGS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/xicq/main ${PREFIX}/bin/xicq
		${MKDIR} ${PREFIX}/share/examples/xicq
.for file in contact config
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/examples/xicq
.endfor

.include <bsd.port.post.mk>
