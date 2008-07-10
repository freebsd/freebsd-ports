# New ports collection makefile for:	routers2
# Date created:				December 14th 2006
# Whom:	      				Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	routers2-extras
PORTVERSION=	2.18
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.steveshipway.org/software/rrd/ \
		ftp://ftp.oav.oav.net/routers2/
DISTNAME=	routers2-v${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	Extra extensions and scripts for routers2 frontend

RUN_DEPENDS=	${LOCALBASE}/www/routers2/routers2.cgi:${PORTSDIR}/net-mgmt/routers2 \
		${LOCALBASE}/bin/mrtg-ping-probe:${PORTSDIR}/net-mgmt/mrtg-ping-probe

WRKSRC=		${WRKDIR}/routers2-v${PORTVERSION}/extras

USE_PERL5=	YES

NO_BUILD=	YES

post-patch:
	for file in buildwan.pl cfgmaker_host.pl 95.pl ; do \
		${REINPLACE_CMD} -e 's|%%PERL%%|${PERL}|' ${WRKSRC}/$$file; \
	done
	for file in cfgmaker_host.pl ; do \
		${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/$$file; \
	done

do-install:
		${MKDIR} -m 755 ${PREFIX}/www/routers2/extras
.if !defined(NOPORTDOCS)
		${MKDIR} -m 755 ${DOCSDIR}
		for file in README *.txt; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${DOCSDIR}; \
		done
.endif
		for file in buildwan.pl cfgmaker_host.pl check_esx2 check_foundry checkagent \
			gather.pl getstats.sh graphprune.pl mrtg-apache mrtg-nrpe.pl mrtg-nrpe.sh \
			mrtg-pnsclient.pl mrtg-portsinuse.pl rrd-archive-clean.pl \
			rrd-archive.pl rrdextend.pl vmware_monitor.pl vmware_monitor2.pl \
			winalert.pl targetnames/targetnames.pl 95.pl; do \
			${INSTALL_SCRIPT} ${WRKSRC}/$$file ${PREFIX}/www/routers2/extras; \
		done
		for file in mrtg-nrpe.cfg mrtg-pnsclient.cfg rrd-archive.conf winalert.conf ; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/www/routers2/extras; \
		done
		${MKDIR} -m 755 ${PREFIX}/www/routers2/extras/templates
		for file in templates/* ; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/www/routers2/extras/templates; \
		done

.include <bsd.port.mk>
