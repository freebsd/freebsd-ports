# New ports collection makefile for:	nn
# Version required:	6.5.0
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.14 1997/07/30 18:17:48 adam Exp $
#

DISTNAME=	nn-6.5.3
EXTRACT_SUFX=	.tar.Z
CATEGORIES=	news
#MASTER_SITES=	ftp://ftp.isca.uiowa.edu/unix/nn/
MASTER_SITES=	ftp://ftp.visi.com/users/mtpins/
MAINTAINER=     ports@FreeBSD.ORG

MAN1=		nn.1 nncheck.1 nngoback.1 nngrab.1  nngrep.1 nnpost.1 \
		nntidy.1 nnview.1 nnacct.1m nnadmin.1m nnstats.1m nnusage.1m
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
