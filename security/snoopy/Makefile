# New ports collection makefile for:   snoopy
# Date created:                3 February 2007
# Whom:                        Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	snoopy
PORTVERSION=	1.8.0
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}logger/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	An execve() wrapper and logger

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	lib/snoopy.so bin/detect
PORTDOCS=	README

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' ${WRKSRC}/README
	@${REINPLACE_CMD} '/^LIBS.*/d' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snoopy.so ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/detect ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
