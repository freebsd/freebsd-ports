# Created by: Xavier Beaudouin <kiwi@oav.net>
# $FreeBSD$

PORTNAME=	routers2-extras
PORTVERSION=	2.19
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.steveshipway.org/software/rrd/ \
		ftp://ftp.oav.oav.net/routers2/
DISTNAME=	routers2-v${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	Extra extensions and scripts for routers2 frontend

RUN_DEPENDS=	${LOCALBASE}/www/routers2/routers2.cgi:${PORTSDIR}/net-mgmt/routers2 \
		${LOCALBASE}/bin/mrtg-ping-probe:${PORTSDIR}/net-mgmt/mrtg-ping-probe

WRKSRC=		${WRKDIR}/routers2-v${PORTVERSION}/extras

USES=		perl5
NO_BUILD=	YES
PORTDOCS=	README *.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|%%PERL%%|${PERL}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/buildwan.pl \
		${WRKSRC}/cfgmaker_host.pl \
		${WRKSRC}/95.pl

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/routers2/extras/templates
	cd ${WRKSRC}; ${INSTALL_SCRIPT} buildwan.pl cfgmaker_host.pl \
		check_vmware.pl check_foundry checkagent gather.pl \
		getstats.sh graphprune.pl mrtg-apache mrtg-nrpe.pl \
		mrtg-nrpe.sh mrtg-pnsclient.pl mrtg-portsinuse.pl \
		rrd-archive-clean.pl rrd-archive.pl rrdextend.pl \
		winalert.pl targetnames/targetnames.pl \
		${STAGEDIR}${PREFIX}/www/routers2/extras
	cd ${WRKSRC}; ${INSTALL_DATA} mrtg-nrpe.cfg mrtg-pnsclient.cfg \
		rrd-archive.conf winalert.conf \
		${STAGEDIR}${PREFIX}/www/routers2/extras
	cd ${WRKSRC}; ${INSTALL_DATA} mrtg-templates/* \
		${STAGEDIR}${PREFIX}/www/routers2/extras/templates
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README *.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
