# New ports collection makefile for:	nntp
# Date created:		29 September 1994
# Whom:			adam
#
# $FreeBSD$
#

PORTNAME=	nntp
PORTVERSION=	1.5.12.2
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.academ.com/pub/nntp/server/
DISTNAME=	${PORTNAME}.${PORTVERSION}

PATCH_SITES=	ftp://ftp.lan-ks.de/pub/c-news/ \
		ftp://ftp.dinoex.org/pub/c-news/
PATCHFILES=	nntp-patch-y2k

MAINTAINER=	dinoex@freebsd.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libcnews.a:${PORTSDIR}/news/cnews

NO_WRKSUBDIR=	yes
MAN1=		nntpxmit.1
MAN8=		nntpd.8c acttimes.8c
PLIST_SUB+=	NEWSBIN=${NEWSBIN:S=${PREFIX}/==}
PLIST_SUB+=	NEWSCTL=${NEWSCTL:S=${PREFIX}/==}

MODIFY=		conf.h Makefile

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
		-e "s=/usr/local/sbin=${PREFIX}/sbin=" \
		-e "s=/usr/local/man=${PREFIX}/man=" \
		${WRKSRC}/${i}.sed >${WRKSRC}/${i}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/overview.fmt ${NEWSCTL}/overview.fmt

.include <bsd.port.mk>
