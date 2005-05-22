# New ports collection makefile for:	mmv
# Date created:		2 Feb 1995
# Whom:			Michael Elbel (me)
#
# $FreeBSD$
#

PORTNAME=	mmv
PORTVERSION=	1.01b
CATEGORIES=	misc
MASTER_SITES=	http://custom.lab.unb.br/pub/unix-c/file-mgmt/
DISTNAME=	mmv
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Move/copy/append/link multiple files with sophisticated wildcard matching

NO_CDROM=	"No redistribution for charge"
NO_PACKAGE=	"No modification"
CFLAGS+=	-DDIRENT
MAKE_FLAGS=	-e
MAN1=		mmv.1

post-extract:
	(cd ${WRKSRC} ; \
	 ${CAT} mmv.c.? >mmv.c ; \
	 ${PATCH} mmv.c < mmv.patch1 ; )

do-install:
	(cd ${PREFIX}/bin ; ${RM} -f mmv mad mcp mln ; \
	 ${INSTALL_PROGRAM} ${WRKSRC}/mmv ${PREFIX}/bin ; \
	 ${LN} -fs ${PREFIX}/bin/mmv ${PREFIX}/bin/mad ; \
	 ${LN} -fs ${PREFIX}/bin/mmv ${PREFIX}/bin/mcp ; \
	 ${LN} -fs ${PREFIX}/bin/mmv ${PREFIX}/bin/mln ; \
	 ${INSTALL_MAN} ${WRKSRC}/mmv.1 ${PREFIX}/man/man1 ; )

.include <bsd.port.mk>
