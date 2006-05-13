# New ports collection makefile for: 	nikto
# Date created: 			23 September 2002
# Whom: 				pandzilla
#
# $FreeBSD$
#
# $Tecnik: ports/security/nikto/Makefile,v 1.7 2005/12/13 16:26:20 itetcu Exp $
#

PORTNAME=	nikto
PORTVERSION=	1.35
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://www.cirt.net/${PORTNAME}/ \
		http://www.mirrors.wiretapped.net/security/vulnerability-assessment/${PORTNAME}/ \
		http://people.tecnik93.com/~itetcu/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Web and CGI vulnerability scanner with SSL support

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes

PORTDOCS=	CHANGES.txt README_plugins.txt nikto_usage.html nikto_usage.txt
MAN1=		${PORTNAME}.1

OPTIONS+=	SSLEAY "Use NET::SSLeay for ssl scanning" on
OPTIONS+=	NMAP "Use security/nmap for port scanning" on

.include <bsd.port.pre.mk>

.ifdef(WITH_SSLEAY)
RUN_DEPENEDS+=	p5-Net-SSLeay>0:${PORTSDIR}/security/p5-Net-SSLeay
.endif

.ifdef(WITH_NMAP)
RUN_DEPENEDS+=	nmap:${PORTSDIR}/security/nmap
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local/bin/perl|${PERL}|" ${WRKSRC}/nikto.pl
	@${REINPLACE_CMD} -Ee "s,(config.txt),${PREFIX}/etc/nikto.conf," ${WRKSRC}/nikto.pl
	@${REINPLACE_CMD} -Ee "s|/usr/bin/nmap|${PREFIX}/bin/nmap|g" \
		-e "s|# (PLUGINDIR=)/usr/local/nikto/plugins|\1${DATADIR}|g" \
		${WRKSRC}/config.txt
	@${REINPLACE_CMD} "s/config.txt/nikto.conf/g" ${WRKSRC}/plugins/* ${WRKSRC}/docs/*
	@${MV} ${WRKSRC}/docs/nikto-1.34.man ${WRKSRC}/docs/nikto.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nikto.pl ${PREFIX}/bin/nikto
	${INSTALL_DATA} ${WRKSRC}/config.txt ${PREFIX}/etc/nikto.conf.sample
	[ -f ${PREFIX}/etc/nikto.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/config.txt ${PREFIX}/etc/nikto.conf
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/LW.pm ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/*.db ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/nikto_plugin_order.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/*.plugin ${DATADIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.	for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.	endfor
.endif
	${INSTALL_MAN} ${WRKSRC}/docs/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
