# ports collection Makefile for: leafnode
# Whom:			Brian Somers <brian@FreeBSD.org>
# Date created:		1997-06-27
#
# $FreeBSD$
#

PORTNAME=	leafnode
PORTVERSION=	1.9.29
CATEGORIES=	news
MASTER_SITES=	http://dl.sourceforge.net/sourceforge/leafnode/ \
		http://www.dt.e-technik.uni-dortmund.de/~ma/${PORTNAME}/ \
		ftp://wpxx02.toxi.uni-wuerzburg.de/pub/ \
		http://www.Awfulhak.org/leafnode/ \
		${MASTER_SITE_SUNSITE}/system/news/transport/ \
		ftp://ftp.karlsruhe.org/pub/news/servers/leafnode/ \
		ftp://ftp.stikman.com/pub/leafnode/ \
		ftp://ftp.gigabell.net/pub/leafnode/
DISTNAME=	${PORTNAME}-${PORTVERSION}.rel

MAINTAINER=	matthias.andree@web.de

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet --sysconfdir=${LOCALBASE}/etc/leafnode \
		--with-lockfile=/var/spool/lock/news/leafnode.lck \
		--with-spooldir=/var/spool/news
MAKE_ARGS=
MAN1=		newsq.1
MAN8=		applyfilter.8 checkgroups.8 fetchnews.8 leafnode.8 texpire.8

post-install:
		${INSTALL_SCRIPT} ${WRKSRC}/setup-daemontools.sh ${LOCALBASE}/sbin/
.if !defined(NOPORTDOCS)
		${MKDIR} ${LOCALBASE}/share/doc/${PORTNAME}
		for i in ChangeLog COPYING CREDITS FAQ.txt FAQ.pdf FAQ.html \
			 INSTALL NEWS README \
			 README-FQDN README-FQDN.html README-daemontools \
			 README.FIRST TODO ; do \
		  ${INSTALL_MAN} ${WRKSRC}/$$i \
			${LOCALBASE}/share/doc/${PORTNAME} ; done
		${MKDIR} ${LOCALBASE}/share/doc/${PORTNAME}/doc_german
		for i in INSTALL_de LIESMICH-daemontools README \
			README_de ${MAN1} ${MAN8} ; do \
		  ${INSTALL_MAN} ${WRKSRC}/doc_german/$$i \
			${LOCALBASE}/share/doc/${PORTNAME}/doc_german ; done
.endif
		${CAT} pkg-message

.include <bsd.port.mk>
