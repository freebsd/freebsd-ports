# Created by: Xavier Beaudouin <kiwi@oav.net>
# $FreeBSD$

PORTNAME=	routers2-extras
PORTVERSION=	2.23
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.steveshipway.org/software/rrd/ \
		ftp://ftp.oav.oav.net/routers2/
DISTNAME=	routers2-v${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	Extra extensions and scripts for routers2 frontend

RUN_DEPENDS=	${LOCALBASE}/www/routers2/routers2.cgi:net-mgmt/routers2 \
		${LOCALBASE}/bin/mrtg-ping-probe:net-mgmt/mrtg-ping-probe

WRKSRC=		${WRKDIR}/routers2-v${PORTVERSION}/extras

USES=		perl5 shebangfix
SHEBANG_FILES=	check_foundry check_vmware.pl \
		checkagent gather.pl graphprune.pl \
		mrtg-apache mrtg-nrpe.pl mrtg-pnsclient.pl \
		mrtg-portsinuse.pl rrd-archive-clean.pl \
		rrd-archive.pl rrdextend.pl \
		winalert.pl
NO_BUILD=	yes
NO_ARCH=	yes
PORTDOCS=	README *.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e '1s|#!perl|#!${perl_CMD}|' \
		${WRKSRC}/targetnames/targetnames.pl
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

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README *.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
