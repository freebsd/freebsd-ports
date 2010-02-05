# New ports collection makefile for:	nagiosgraph
# Date created:				Wed May  3 17:26:19 MSD 2006
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	nagiosgraph
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	hizel@vyborg.ru
COMMENT=	Generate rrdtool\'s graphs by performance data from nagios plugins

RUN_DEPENDS=	${LOCALBASE}/bin/nagios:${PORTSDIR}/net-mgmt/nagios \
		${SITE_PERL}/${PERL_ARCH}/RRDs.pm:${PORTSDIR}/databases/rrdtool

USE_PERL5_RUN=	yes
NO_BUILD=	yes

PORTDOCS=	AUTHORS CHANGELOG INSTALL README README.map TODO

PLIST_SUB=	NAGIOSWWWDIR=${NAGIOSWWWDIR}

NAGIOSWWWDIR?=	www/nagios

post-patch:
.for i in lib/insert.pl cgi/show.cgi cgi/showgraph.cgi cgi/showhost.cgi cgi/showservice.cgi cgi/testcolor.cgi
	${REINPLACE_CMD} -e 's!/usr/bin/perl!${PERL}!g' -e 's!/usr/local!${PREFIX}!g' \
		-e 's!/etc/nagios/!/usr/local/etc/nagios/!g' ${WRKSRC}/$i
.endfor

do-install:
	${MKDIR} ${PREFIX}/etc/nagios/nagiosgraph

	${INSTALL_DATA} ${WRKSRC}/etc/ngshared.pm ${PREFIX}/etc/nagios/nagiosgraph/ngshared.pm

.for i in hostdb.conf map nagiosgraph.conf servdb.conf
	${INSTALL_DATA} ${WRKSRC}/etc/$i ${PREFIX}/etc/nagios/nagiosgraph/${i}.example
.endfor

	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/lib/insert.pl ${PREFIX}/libexec/${PORTNAME}

	${MKDIR} ${PREFIX}/${NAGIOSWWWDIR}/cgi-bin/nagiosgraph
.for i in cgi/show.cgi cgi/showgraph.cgi cgi/showhost.cgi cgi/showservice.cgi cgi/testcolor.cgi
	${INSTALL_SCRIPT} ${WRKSRC}/$i ${PREFIX}/${NAGIOSWWWDIR}/cgi-bin/nagiosgraph
.endfor

	${MKDIR} ${PREFIX}/${NAGIOSWWWDIR}/stylesheets
.for i in share/action.gif share/nagiosgraph.css share/nagiosgraph.js
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/${NAGIOSWWWDIR}/stylesheets
.endfor

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for i in utils/authz.pl utils/testentry.pl utils/upgrade.pl
	${INSTALL_SCRIPT} ${WRKSRC}/$i ${EXAMPLESDIR}
.endfor
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
