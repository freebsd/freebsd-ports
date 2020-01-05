# Created by: Mark Linimon <linimon@lonesome.com>
# $FreeBSD$

PORTNAME=	hinfo
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	net perl5
# note: the "true" MASTER_SITE is http://www.blars.org, but
# due to policies on that site, it is not reachable from the
# FreeBSD build machines.
MASTER_SITES=	http://www.lonesome.com/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility primarily designed to find the owner of an IP block

BROKEN=		unfetchable

RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS \
		wget:ftp/wget

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	${HINFO_SCRIPTS}

DATADIR?=	${PREFIX}/lib/${PORTNAME}

HINFO_DBFILES=	dnsbl.ins.pl whois.ins.pl
# By default, we don't install myhostinfo.cgi.  Install it if you wish; it'll
# already be patched for you.
HINFO_SCRIPTS=	hinfo hinfo-update myhostinfo.cgi

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hinfo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/hinfo-update ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/hinfo.conf ${STAGEDIR}${PREFIX}/etc/hinfo.conf.sample
	${INSTALL_MAN} ${WRKSRC}/hinfo.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/hinfo.conf.5 ${STAGEDIR}${PREFIX}/man/man5/
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for filename in ${HINFO_DBFILES}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
