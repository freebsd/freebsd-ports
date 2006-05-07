# New ports collection makefile for:	nagiosgraph
# Date created:				Wed May  3 17:26:19 MSD 2006
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	nagiosgraph
PORTVERSION=	0.8.2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dsh@vlink.ru
COMMENT=	Generate rrdtool's graphs by performance data from nagios plugins

RUN_DEPENDS=	${LOCALBASE}/bin/nagios:${PORTSDIR}/net-mgmt/nagios \
		${SITE_PERL}/${PERL_ARCH}/RRDs.pm:${PORTSDIR}/net/rrdtool

USE_PERL5_RUN=	yes
NO_BUILD=	yes

PORTDOCS=	CHANGELOG INSTALL README README.map

PLIST_SUB=	NAGIOSWWWDIR=${NAGIOSWWWDIR}

NAGIOSWWWDIR?=	www/nagios

post-patch:
.for i in insert.pl show.cgi testcolor.cgi testentry.pl
	${REINPLACE_CMD} -e 's!/usr/bin/perl!${PERL}!g' -e 's!/usr/local!${PREFIX}!g' -e 's!nagiosgraph\.conf!nagios/nagiosgraph/nagiosgraph.conf!g' ${WRKSRC}/$i
.endfor

do-install:
	${MKDIR} ${PREFIX}/etc/nagios/nagiosgraph
.for i in map nagiosgraph.conf
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/etc/nagios/nagiosgraph/${i}.example
.endfor

	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/insert.pl ${PREFIX}/libexec/${PORTNAME}

	${MKDIR} ${PREFIX}/${NAGIOSWWWDIR}/cgi-bin/nagiosgraph
.for i in show.cgi testcolor.cgi
	${INSTALL_SCRIPT} ${WRKSRC}/$i ${PREFIX}/${NAGIOSWWWDIR}/cgi-bin/nagiosgraph
.endfor

	${MKDIR} ${PREFIX}/${NAGIOSWWWDIR}/stylesheets
	${INSTALL_DATA} ${WRKSRC}/nagiosgraph.css ${PREFIX}/${NAGIOSWWWDIR}/stylesheets

	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/testentry.pl ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
