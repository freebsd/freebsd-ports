# New ports collection makefile for:	hinfo
# Date created:				Mon Mar 31 22:37:48 CST 2003
# Whom:					Mark Linimon <linimon@lonesome.com>
#
# $FreeBSD$
#

PORTNAME=	hinfo
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net perl5
# note: the "true" MASTER_SITE is http://www.blars.org, but
# due to policies on that site, it is not reachable from the
# FreeBSD build machines.
MASTER_SITES=	http://www.lonesome.com/FreeBSD/distfiles/

MAINTAINER=	linimon@lonesome.com
COMMENT=	Utility primarily designed to find the owner of an IP block

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		wget:${PORTSDIR}/ftp/wget/

USE_PERL5_RUN=	yes
USE_REINPLACE=	yes

DATADIR?=	${PREFIX}/lib/${PORTNAME}

HINFO_DBFILES=	dnsbl.ins.pl whois.ins.pl
HINFO_SCRIPTS=	hinfo hinfo-update myhostinfo.cgi

#MAN1=		hinfo.1
#MAN5=		hinfo.conf.5

NO_BUILD=	yes

# By default, we don't install myhostinfo.cgi.  Install it if you wish; it'll
# already be patched for you.
post-extract:
.for filename in ${HINFO_SCRIPTS}
	${REINPLACE_CMD} -E '1s|^#!.+|#!${PERL}|' ${WRKSRC}/${filename}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hinfo ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/hinfo-update ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/hinfo.conf ${PREFIX}/etc/hinfo.conf.example
.if !exists({PREFIX}/etc/hinfo.conf)
	${INSTALL_DATA} ${WRKSRC}/hinfo.conf ${PREFIX}/etc/hinfo.conf
.endif
.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/hinfo.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/hinfo.conf.5 ${PREFIX}/man/man5/
.endif
	@${MKDIR} ${DATADIR}
.for filename in ${HINFO_DBFILES}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DATADIR}
.endfor

.include <bsd.port.mk>
