# New ports collection makefile for:	xwpl
# Date created:		31 Nov 97
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	xwpl
PORTVERSION=	1.3
CATEGORIES=	math
MASTER_SITES=	# no longer available
DISTNAME=	${PKGNAME}-freebsd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The X Wavelet Packet Laboratory

ONLY_FOR_ARCHS=	i386

NO_CDROM=	"Free for Non-Commercial Use Only"
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/xwpl
STRIP=

MAN1=		xwpl.1

do-install:
	${INSTALL_PROGRAM} $(WRKSRC)/xwpl $(PREFIX)/bin
	${INSTALL_MAN} ${WRKSRC}/xwpl.man ${PREFIX}/man/man1/xwpl.1

post-install:
	${MKDIR} $(PREFIX)/share/examples/xwpl
	${INSTALL_DATA} ${WRKSRC}/data/* $(PREFIX)/share/examples/xwpl
.if !defined(NOPORTDOCS)
	${MKDIR} $(PREFIX)/share/doc/xwpl
	${INSTALL_DATA} ${WRKSRC}/*.ps $(PREFIX)/share/doc/xwpl
	${INSTALL_DATA} ${WRKSRC}/README $(PREFIX)/share/doc/xwpl
.endif

.include <bsd.port.mk>
