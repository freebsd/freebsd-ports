# ports collection Makefile for: leafnode
# Whom:			Brian Somers <brian@FreeBSD.org>
# Date created:		1997-06-27
#
# $FreeBSD$
#

PORTNAME=	leafnode
PORTVERSION=	1.9.34
PORTREVISION=	0
CATEGORIES=	news ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:sourceforge/} \
		http://www.dt.e-technik.uni-dortmund.de/~ma/${PORTNAME}/ \
		ftp://wpxx02.toxi.uni-wuerzburg.de/pub/ \
		${MASTER_SITE_SUNSITE:S/$/:sunsite/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:sourceforge \
			./:DEFAULT \
			system/news/transport/:sunsite
DISTNAME=	${PORTNAME}-${PORTVERSION}.rel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sourceforge,sunsite,DEFAULT

MAINTAINER=	matthias.andree@web.de
COMMENT=	USENET software package designed for small sites

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet --sysconfdir=${LOCALBASE}/etc/leafnode \
		--with-lockfile=/var/spool/lock/news/leafnode.lck \
		--with-spooldir=/var/spool/news --with-ipv6
CONFIGURE_TARGET=    --build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS=
MAN1=		leafnode-version.1 newsq.1
MAN8=		applyfilter.8 checkgroups.8 fetchnews.8 leafnode.8 texpire.8

post-install:
		${INSTALL_SCRIPT} ${WRKSRC}/setup-daemontools.sh ${LOCALBASE}/sbin/
.if !defined(NOPORTDOCS)
		${MKDIR} ${LOCALBASE}/share/doc/${PORTNAME}
		for i in ChangeLog COPYING CREDITS FAQ.txt FAQ.pdf FAQ.html \
			 INSTALL NEWS README \
			 README-FQDN README-FQDN.html README-daemontools \
			 README.FIRST TODO leafnode.cron.daily ; do \
		  ${INSTALL_MAN} ${WRKSRC}/$$i \
			${LOCALBASE}/share/doc/${PORTNAME} ; done
		${MKDIR} ${LOCALBASE}/share/doc/${PORTNAME}/doc_german
		for i in INSTALL_de LIESMICH-daemontools README \
			README_de newsq.1 ${MAN8} ; do \
		  ${INSTALL_MAN} ${WRKSRC}/doc_german/$$i \
			${LOCALBASE}/share/doc/${PORTNAME}/doc_german ; done
.endif
		${CAT} pkg-message

.include <bsd.port.mk>
