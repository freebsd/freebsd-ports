# New ports collection makefile for:	leafnode
# Date created:		10 April 1996
# Whom:			Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	leafnode
PORTVERSION=	1.9.22
CATEGORIES=	news
MASTER_SITES=	ftp://wpxx02.toxi.uni-wuerzburg.de/pub/ \
		http://www.Awfulhak.org/leafnode/ \
		${MASTER_SITE_SUNSITE} \
		ftp://ftp.karlsruhe.org/pub/news/servers/leafnode/ \
		ftp://ftp.stikman.com/pub/leafnode/ \
		ftp://ftp.gigabell.net/pub/leafnode/
MASTER_SITE_SUBDIR=	system/news/transport
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.rel

MAINTAINER=	brian@FreeBSD.org

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet --sysconfdir=${LOCALBASE}/etc/leafnode \
		--with-lockfile=/var/spool/lock/news/leafnode.lck \
		--with-spooldir=/var/spool/news
MAKE_ARGS=
MAN1=		newsq.1
MAN8=		applyfilter.8 checkgroups.8 fetchnews.8 leafnode.8 texpire.8

post-install:
.if !defined(NOPORTDOCS)
		${MKDIR} ${LOCALBASE}/share/doc/${PORTNAME}
		for i in ChangeLog CREDITS FAQ INSTALL NEWS README \
			 README.FIRST TODO ; do \
		  ${INSTALL_MAN} ${WRKSRC}/$$i \
			${LOCALBASE}/share/doc/${PORTNAME} ; done
.endif
		${CAT} pkg-message

.include <bsd.port.mk>
