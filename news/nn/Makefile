# New ports collection makefile for:	nn
# Version required:	6.5.0
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.13 1997/06/19 06:54:39 asami Exp $
#

DISTNAME=	nn-6.5.0.b3
PKGNAME=	nn-6.5.0
CATEGORIES=	news
MASTER_SITES=	ftp://uniwa.uwa.edu.au/pub/nn/old/beta/
MAINTAINER=     ports@FreeBSD.ORG

MAN1=		nn.1 nncheck.1 nngoback.1 nngrab.1  nngrep.1 nnpost.1 \
		nntidy.1 nnacct.1 nnadmin.1 nnstats.1 nnusage.1
MAN8=		nnmaster.8 nnspew.8

pre-patch:
	@${CP} ${WRKSRC}/config.h-dist ${WRKSRC}/config.h

pre-build:
	@${CP} ${FILESDIR}/s-freebsd.h ${WRKSRC}/conf

pre-install:
	${MKDIR} ${PREFIX}/news
	[ -r ${PREFIX}/news/lib/inews ] || ( cd ${WRKSRC}/inews; ${MAKE} all )
	[ -r ${PREFIX}/news/lib/inews ] || ( cd ${WRKSRC}/inews; ${MAKE} install )

post-install:
	@${ECHO} Put your NNTP host into ${PREFIX}/etc/nntpserver file

.include <bsd.port.mk>
