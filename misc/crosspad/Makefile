# New ports collection makefile for:	crosspad
# Version required:	981015a
# Date created:		23 September 1998
# Whom:			itojun@itojun.org
#
# $Id: Makefile,v 1.6 1998/09/14 06:38:04 itojun Exp $
#

DISTNAME=	crosspad-981015a
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.itojun.org/pub/misc/

MAINTAINER=	itojun@itojun.org

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
