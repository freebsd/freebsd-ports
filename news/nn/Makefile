# New ports collection makefile for:	nn
# Version required:	6.5.3
# Date created:		24 September 1994
# Whom:			adam
#
# $FreeBSD$
#

DISTNAME=	nn-6.5.3
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.visi.com/users/mtpins/ \
		ftp://maroon.webmaster.com/pub/nn/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     ports@FreeBSD.org
MAINTAINER=	jooji@webnology.com

IS_INTERACTIVE=	yes
NO_PACKAGE=	posting depends on inews utility, which has poster\'s domain compiled in

MAN1=		nn.1 nncheck.1 nngoback.1 nngrab.1  nngrep.1 nnpost.1 \
		nntidy.1 nnview.1 nnacct.1m nnadmin.1m nnstats.1m nnusage.1m
MAN8=		nnmaster.8 nnspew.8

pre-patch:
	@${CP} ${WRKSRC}/config.h-dist ${WRKSRC}/config.h

pre-build:
	@${CP} ${FILESDIR}/s-freebsd.h ${WRKSRC}/conf

pre-install:
	@${MKDIR} ${PREFIX}/news
	[ ! -f ${WRKDIR}/.install_inews ] || (cd ${WRKSRC}/inews; ${MAKE} all)
	[ ! -f ${WRKDIR}/.install_inews ] || (cd ${WRKSRC}/inews; ${MAKE} install)

post-install:
	@${CP} ${WRKDIR}/nntp_server ${PREFIX}/etc/nntp_server

.include <bsd.port.mk>
