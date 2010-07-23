# New ports collection makefile for: 	nikto
# Date created: 			23 September 2002
# Whom: 				pandzilla
#
# $FreeBSD$
#
# $Tecnik: ports/security/nikto/Makefile,v 1.7 2005/12/13 16:26:20 itetcu Exp $
#

PORTNAME=	nikto
PORTVERSION=	2.1.2
PORTEPOCH=	1
CATEGORIES=	security www
MASTER_SITES=	http://www.cirt.net/${PORTNAME}/ \
		http://www.mirrors.wiretapped.net/security/vulnerability-assessment/${PORTNAME}/

MAINTAINER=	niels@freebsd.org
COMMENT=	Web and CGI vulnerability scanner with SSL support

MAN1=		nikto.1

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes

PORTDOCS=	CHANGES.txt LICENSE.txt nikto.dtd nikto_manual.html

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
	@${REINPLACE_CMD} -e "s|/etc/nikto.conf|${PREFIX}/etc/nikto.conf|" ${WRKSRC}/nikto.pl
	@${REINPLACE_CMD} -Ee "s|/usr/bin/nmap|${LOCALBASE}/bin/nmap|g" \
		-e "s|# (EXECDIR=)/usr/local/nikto|\1${DATADIR}|g" \
		${WRKSRC}/nikto.conf
	@${REINPLACE_CMD} -e 's:\$NIKTO{plugindir}/../docs/CHANGES.txt:\$NIKTO{plugindir}/../../docs/nikto/CHANGES.txt:' \
		-e 's:\$NIKTO{plugindir}/../CHANGES.txt:\$NIKTO{plugindir}/../../docs/nikto/CHANGES.txt:' \
		${WRKSRC}/plugins/nikto_core.plugin
	@${RM} ${WRKSRC}/plugins/*.bak

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nikto.pl ${PREFIX}/bin/nikto
	${INSTALL_DATA} ${WRKSRC}/nikto.conf ${PREFIX}/etc/nikto.conf.sample
	${INSTALL_MAN} ${WRKSRC}/docs/nikto.1 ${PREFIX}/man/man1/
	[ -f ${PREFIX}/etc/nikto.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/nikto.conf ${PREFIX}/etc/nikto.conf
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/plugins
	@${MKDIR} ${DATADIR}/templates
	${INSTALL_DATA} ${WRKSRC}/plugins/LW2.pm ${DATADIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/db_* ${DATADIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/*.plugin ${DATADIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/templates/*.tmpl ${DATADIR}/templates
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.	for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.	endfor
.endif

.include <bsd.port.post.mk>
