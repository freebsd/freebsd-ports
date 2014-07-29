# Created by: Xavier Beaudouin <kiwi@oav.net>
# $FreeBSD$

PORTNAME=	routers2-extensions
PORTVERSION=	2.19
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.steveshipway.org/software/rrd/ \
		ftp://ftp.oav.oav.net/routers2/
DISTNAME=	routers2-v${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	Extensions of routers2 frontend

RUN_DEPENDS=	${LOCALBASE}/www/routers2/routers2.cgi:${PORTSDIR}/net-mgmt/routers2 \
		p5-Net-Telnet-Cisco>=0:${PORTSDIR}/net-mgmt/p5-Telnet-Cisco \
		${LOCALBASE}/bin/htmldoc:${PORTSDIR}/textproc/htmldoc

WRKSRC=		${WRKDIR}/routers2-v${PORTVERSION}/extensions

USES=		perl5

NO_BUILD=	YES
PORTDOCS=	README *.txt extension.cgi.pl

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/*.cgi

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/routers2/extensions
	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi \
		${STAGEDIR}${PREFIX}/www/routers2/extensions
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README *.txt extension.cgi.pl \
		${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
