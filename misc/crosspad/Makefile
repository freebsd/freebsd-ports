# New ports collection makefile for:	crosspad
# Date created:		23 September 1998
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	crosspad
PORTVERSION=	19991202
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.itojun.org/pub/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Crosspad data downloader/converter

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/crosspad/build

MAN1=	crosspad2ps.1 crosspad2eps.1 crosspad2tgif.1 crosspad2idraw.1 \
	padload.1

DOCS=	PROTOCOL README.english README.japanese

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/crosspad
	for i in $(DOCS); do \
		${INSTALL_DATA} ${WRKSRC}/../$$i ${PREFIX}/share/doc/crosspad; \
	done
.endif

.include <bsd.port.mk>
