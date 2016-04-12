# Created by: Uwe Pierau <uwe.pierau@tu-clausthal.de>
# $FreeBSD$

PORTNAME=	lacheck
PORTVERSION=	1.26
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.math.utah.edu/pub/lacheck/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for finding common mistakes in LaTeX documents

PLIST_FILES=	bin/lacheck \
		man/man1/lacheck.1.gz
ALL_TARGET=	lacheck lacheck.1


post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}| ; \
		 s|^CC|# CC|; s|^CFLAGS|# CFLAGS|' \
		 ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lacheck ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lacheck.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
