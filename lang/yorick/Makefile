# New ports collection makefile for:	Yorick
# Date created:         26 Oct 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	yorick
PORTVERSION=	1.4.1
CATEGORIES=	lang math
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/Yorick/		\
		ftp://wuarchive.wustl.edu/languages/yorick/
DISTNAME=	yorick-1.4

PATCH_SITES=	ftp://ftp-icf.llnl.gov/pub/Yorick/
PATCHFILES=	yorick-1.4.diff.gz
PATCH_DIST_STRIP=-p1

MAINTAINER=	giffunip@asme.org

USE_XLIB=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=
MAN1=		yorick.1 gist.1

post-install:
	strip	$(PREFIX)/bin/yorick
	strip	$(PREFIX)/bin/gist
	@${INSTALL_MAN} ${WRKSRC}/yorick.1 ${PREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKSRC}/gist.1 ${PREFIX}/man/man1/
.if defined(NOPORTDOCS)
	${RM} -rf $(PREFIX)/share/yorick/1.4/doc
.endif

.include <bsd.port.mk>
