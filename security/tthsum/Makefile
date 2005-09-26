# New ports collection makefile for:	tthsum
# Date created:				25 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	tthsum
PORTVERSION=	1.1.0
CATEGORIES=	security
MASTER_SITES=	http://wza.digitalbrains.com/source/tthsum/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A command-line utility for generating and checking TTH message digests

USE_GMAKE=	yes
USE_REINPLACE=	yes

MAKE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

PORTDOCS=	Changelog.txt
PLIST_FILES=	bin/tthsum
MAN1=		tthsum.1

post-patch:
	@${REINPLACE_CMD} -E '/^(CC|CFLAGS)/d' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj-${ARCH}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
