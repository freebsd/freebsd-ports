# New ports collection makefile for:	bb
# Date created:				22 June 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		bb
PORTVERSION=		1.2
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.ta.jcu.cz/pub/aa/bb/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games

MAINTAINER=		ports@FreeBSD.org

LIB_DEPENDS=		aa.1:${PORTSDIR}/graphics/aalib

MAKEFILE=		makefile
GNU_CONFIGURE=		yes

pre-patch:
	${FIND} ${WRKSRC} -type f | ${XARGS} ${PERL} -pi -e "s@#include +<malloc.h>@#include <stdlib.h>@g"

pre-build:
	@ cd ${WRKSRC}/mikunix; make

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bb ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bb_snd_server ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/bb
.for file in bb bb2 bb3
	@ ${INSTALL_DATA} ${WRKSRC}/${file}.s3m ${PREFIX}/share/bb
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ANNOUNCE COPYING README
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
