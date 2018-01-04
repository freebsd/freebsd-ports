# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	nagiosgraph
PORTVERSION=	1.5.2
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	hizel@vyborg.ru
COMMENT=	Generate rrdtool graphs using performance data from nagios plugins

LICENSE=	ART20

RUN_DEPENDS=	rrdtool>=0:databases/rrdtool \
		p5-CGI>=0:www/p5-CGI

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		NAGIOS
OPTIONS_SINGLE_NAGIOS=	NAGIOS35 NAGIOS4
OPTIONS_DEFAULT=	NAGIOS35

NAGIOS35_DESC=		Install for nagios-3.5.x (net-mgmt/nagios)
NAGIOS35_RUN_DEPENDS=	${LOCALBASE}/bin/nagios:net-mgmt/nagios

NAGIOS4_DESC=		Install for nagios-4.0.x (net-mgmt/nagios4)
NAGIOS4_RUN_DEPENDS=	${LOCALBASE}/bin/nagios:net-mgmt/nagios4

USES=		perl5 shebangfix
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes

DOCS=		AUTHORS CHANGELOG INSTALL README TODO
NAGIOSWWWDIR?=	www/nagios
CGIFILES=	show.cgi showconfig.cgi showgraph.cgi showgroup.cgi \
		showhost.cgi showservice.cgi testcolor.cgi
LIBFILES=	insert.pl
CFGFILES=	nagiosgraph.conf nagiosgraph_de.conf nagiosgraph_es.conf \
		nagiosgraph_fr.conf servdb.conf groupdb.conf hostdb.conf \
		datasetdb.conf map access.conf labels.conf rrdopts.conf

SHEBANG_FILES=	 utils/*.pl

PLIST_SUB=	NAGIOSWWWDIR=${NAGIOSWWWDIR} PORTNAME=${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's!%%PREFIX%%!${PREFIX}!' \
		${WRKSRC}/etc/nagiosgraph.conf
.for i in ${CGIFILES}
	@${REINPLACE_CMD} -e 's!/usr/bin/perl!${PERL}!g' \
	    -e 's!/usr/local!${PREFIX}!g' \
	    -e 's!/opt/nagiosgraph/etc!${PREFIX}/etc/nagios/nagiosgraph!g' \
		${WRKSRC}/cgi/$i
.endfor

.for i in ${LIBFILES}
	@${REINPLACE_CMD} -e 's!/usr/bin/perl!${PERL}!g' \
	    -e 's!/usr/local!${PREFIX}!g' \
	    -e 's!/opt/nagiosgraph/etc!${PREFIX}/etc/nagios/nagiosgraph!g' \
		${WRKSRC}/lib/$i
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/nagios/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/etc/ngshared.pm \
		${STAGEDIR}${PREFIX}/etc/nagios/${PORTNAME}/ngshared.pm

.for i in ${CFGFILES}
	${INSTALL_DATA} ${WRKSRC}/etc/$i \
		${STAGEDIR}${PREFIX}/etc/nagios/${PORTNAME}/${i}.sample
.endfor

	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.for i in ${LIBFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/lib/${i} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.endfor

	@${MKDIR} ${STAGEDIR}${PREFIX}/${NAGIOSWWWDIR}/cgi-bin/${PORTNAME}
.for i in ${CGIFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/cgi/$i \
		${STAGEDIR}${PREFIX}/${NAGIOSWWWDIR}/cgi-bin/${PORTNAME}/
.endfor

	@${MKDIR} ${STAGEDIR}${PREFIX}/${NAGIOSWWWDIR}/stylesheets
.for i in share/nagiosgraph.css share/nagiosgraph.js share/nagiosgraph.ssi
	${INSTALL_DATA} ${WRKSRC}/$i \
		${STAGEDIR}${PREFIX}/${NAGIOSWWWDIR}/stylesheets/
.endfor

	@${MKDIR} ${STAGEDIR}${PREFIX}/${NAGIOSWWWDIR}/images
	${INSTALL_DATA} ${WRKSRC}/share/graph.gif \
		${STAGEDIR}${PREFIX}/${NAGIOSWWWDIR}/images/action-nagiosgraph.gif

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/utils/testentry.pl ${STAGEDIR}${EXAMPLESDIR}/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
