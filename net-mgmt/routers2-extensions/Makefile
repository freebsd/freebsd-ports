# New ports collection makefile for:	routers2
# Date created:				December 14th 2006
# Whom:	      				Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	routers2-extensions
PORTVERSION=	2.18
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.steveshipway.org/software/rrd/ \
		ftp://ftp.oav.oav.net/routers2/
DISTNAME=	routers2-v${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	Extensions of routers2 frontend

RUN_DEPENDS=	${LOCALBASE}/www/routers2/routers2.cgi:${PORTSDIR}/net-mgmt/routers2 \
		${SITE_PERL}/Net/Telnet/Cisco.pm:${PORTSDIR}/net-mgmt/p5-Telnet-Cisco \
		${LOCALBASE}/bin/htmldoc:${PORTSDIR}/textproc/htmldoc

WRKSRC=		${WRKDIR}/routers2-v${PORTVERSION}/extensions

USE_PERL5=	YES

NO_BUILD=	YES

post-patch:
	for file in *.cgi ; do \
		${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/$$file; \
	done

do-install:
		${MKDIR} -m 755 ${PREFIX}/www/routers2/extensions

.if !defined(NOPORTDOCS)
		${MKDIR} -m 755 ${DOCSDIR}
		for file in README *.txt extension.cgi.pl; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${DOCSDIR}; \
		done
.endif
		for file in *.cgi; do \
			${INSTALL_SCRIPT} ${WRKSRC}/$$file ${PREFIX}/www/routers2/extensions; \
		done

.include <bsd.port.mk>
