# New ports collection makefile for: 	nikto
# Date created: 			23 September 2002
# Whom: 				pandzilla
#
# $FreeBSD$
#

PORTNAME=	nikto
PORTVERSION= 	1.32
CATEGORIES= 	security www

MAINTAINER=	jan@atstake.com
COMMENT=	Web and CGI vulnerability scanner with SSL support

MASTER_SITES=	http://www.cirt.net/nikto/ \
		http://packetstormsecurity.org/UNIX/cgi-scanners/

RUN_DEPENDS = 	${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/libwhisker/LW.pm:${PORTSDIR}/security/libwhisker

NO_BUILD= 	yes
USE_REINPLACE=	yes

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

.include <bsd.port.mk>
