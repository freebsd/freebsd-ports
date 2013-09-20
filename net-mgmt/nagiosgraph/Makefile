# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	nagiosgraph
PORTVERSION=	1.4.4
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	hizel@vyborg.ru
COMMENT=	Generate rrdtool\'s graphs by performance data from nagios plugins

RUN_DEPENDS=	${LOCALBASE}/bin/nagios:${PORTSDIR}/net-mgmt/nagios \
		rrdtool>=0:${PORTSDIR}/databases/rrdtool

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes

PORTDOCS=	AUTHORS CHANGELOG INSTALL README TODO
NAGIOSWWWDIR?=	www/nagios
CGIFILES=	show.cgi showconfig.cgi showgraph.cgi showgroup.cgi showhost.cgi \
		showservice.cgi testcolor.cgi
LIBFILES=	insert.pl
CFGFILES=	nagiosgraph.conf nagiosgraph_de.conf nagiosgraph_es.conf nagiosgraph_fr.conf \
		servdb.conf groupdb.conf hostdb.conf datasetdb.conf map access.conf labels.conf \
		rrdopts.conf

PLIST_SUB=	NAGIOSWWWDIR=${NAGIOSWWWDIR} PORTNAME=${PORTNAME}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's!%%PREFIX%%!${PREFIX}!' ${WRKSRC}/etc/nagiosgraph.conf
.for i in ${CGIFILES}
	@${REINPLACE_CMD} -e 's!/usr/bin/perl!${PERL}!g' -e 's!/usr/local!${PREFIX}!g' \
		-e 's!/opt/nagiosgraph/etc!${PREFIX}/etc/nagios/nagiosgraph!g' \
			${WRKSRC}/cgi/$i
.endfor

.for i in ${LIBFILES}
	@${REINPLACE_CMD} -e 's!/usr/bin/perl!${PERL}!g' -e 's!/usr/local!${PREFIX}!g' \
		-e 's!/opt/nagiosgraph/etc!${PREFIX}/etc/nagios/nagiosgraph!g' \
			${WRKSRC}/lib/$i
.endfor

do-install:
	${MKDIR} ${PREFIX}/etc/nagios/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/etc/ngshared.pm ${PREFIX}/etc/nagios/${PORTNAME}/ngshared.pm

.for i in ${CFGFILES}
	${INSTALL_DATA} ${WRKSRC}/etc/$i ${PREFIX}/etc/nagios/${PORTNAME}/${i}.sample
	[ -f ${PREFIX}/etc/nagios/${PORTNAME}/${i} ] || ${CP} -p ${PREFIX}/etc/nagios/${PORTNAME}/${i}.sample \
		${PREFIX}/etc/nagios/${PORTNAME}/${i}
.endfor

	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
.for i in ${LIBFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/lib/${i} ${PREFIX}/libexec/${PORTNAME}
.endfor

	${MKDIR} ${PREFIX}/${NAGIOSWWWDIR}/cgi-bin/${PORTNAME}
.for i in ${CGIFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/cgi/$i ${PREFIX}/${NAGIOSWWWDIR}/cgi-bin/${PORTNAME}/
.endfor

.for i in share/nagiosgraph.css share/nagiosgraph.js share/nagiosgraph.ssi
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/${NAGIOSWWWDIR}/stylesheets
.endfor

	${INSTALL_DATA} ${WRKSRC}/share/graph.gif ${PREFIX}/${NAGIOSWWWDIR}/images/action-nagiosgraph.gif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for i in utils/testentry.pl utils/upgrade.pl
	${INSTALL_SCRIPT} ${WRKSRC}/$i ${EXAMPLESDIR}/
.endfor
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.  endfor
.endif

.include <bsd.port.mk>
