# New ports collection makefile for:	nntp
# Version required:	t5
# Date created:		29 September 1994
# Whom:			adam
#
# $FreeBSD$
#

DISTNAME=	nntp-t5
PKGNAME=	nntp-1.5.11.5
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.abs.net/unix/ \
		ftp://ftp.ww.net/pub/unix/news/nntp/

MAINTAINER=	adam@veda.is

BUILD_DEPENDS=	${LOCALBASE}/lib/libcnews.a:${PORTSDIR}/news/cnews

MAN1=		nntpxmit.1
MAN8=		nntpd.8c mkgrdates.8c
PLIST=		${WRKDIR}/.PLIST.sed

MODIFY=		conf.h xfer/Makefile xmit/Makefile

NEWSBIN?=	${PREFIX}/news/cnewsbin
NEWSCTL?=	${PREFIX}/news/lib
NEWSARTS?=	/var/news
NEWSOV?=	/var/news/over.view

post-extract:
	@${CP} ${WRKSRC}/conf.h.dist ${WRKSRC}/conf.h

pre-configure:
.for i in ${MODIFY}
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.sed
	${SED} \
		-e "s=/usr/local/news/lib/bin/config=${NEWSBIN}/config=" \
		-e "s=/usr/local/news/cnewsbin=${NEWSBIN}=" \
		-e "s=/usr/local/news/lib=${NEWSCTL}=" \
		-e "s=/var/news/over.view=${NEWSOV}=" \
		-e "s=/var/news=${NEWSARTS}=" \
		-e "s=/usr/local/bin=${PREFIX}/bin=" \
		${WRKSRC}/${i}.sed >${WRKSRC}/${i}
.endfor
	@${SED} \
		-e "s=news/cnewsbin=${NEWSBIN:S=${PREFIX}/==}=" \
		${PKGDIR}/PLIST >${PLIST}

.include <bsd.port.mk>
