# New ports collection makefile for: 	nikto
# Date created: 			23 September 2002
# Whom: 				pandzilla
#
# $FreeBSD$
#

PORTNAME=	nikto
PORTVERSION=	1.34
CATEGORIES=	security www
MASTER_SITES=	http://www.cirt.net/nikto/ \
		ftp://ftp.bay13.net/pub/wiretapped/vulnerability-assessment/nikto/ \
		http://mirror1.internap.com/pub/localareasecurity/wiretapped/vulnerability-assessment/nikto/ \
		ftp://ftp.localareasecurity.com/pub/wiretapped/vulnerability-assessment/nikto/ \
		http://www.mirrors.wiretapped.net/security/vulnerability-assessment/nikto/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web and CGI vulnerability scanner with SSL support

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/libwhisker/LW.pm:${PORTSDIR}/security/libwhisker

NO_BUILD=	yes
USE_REINPLACE=	yes

PORTDOCS=	nikto_usage.txt nikto_usage.html CHANGES.txt README_plugins.txt

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/nikto.pl ${PREFIX}/bin/nikto
	@${MKDIR} ${PREFIX}/etc/nikto && ${CHMOD} 755 ${PREFIX}/etc/nikto
	@${REINPLACE_CMD} -e "s|/usr/bin/nmap|${PREFIX}/bin/nmap|g" ${WRKSRC}/config.txt
	@${REINPLACE_CMD} -e "s|/usr/local/nikto|${PREFIX}/share/nikto|g" ${WRKSRC}/config.txt
	@${INSTALL_DATA} ${WRKSRC}/config.txt ${PREFIX}/etc/nikto/
	@${MKDIR} ${PREFIX}/share/nikto/ && ${CHMOD} 755 ${PREFIX}/share/nikto/
	@for i in `${LS} ${WRKSRC}/plugins/` ; \
	do \
	${INSTALL_SCRIPT} ${WRKSRC}/plugins/$$i ${PREFIX}/share/nikto; \
	done
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
