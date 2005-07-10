# New ports collection makefile for: 	nikto
# Date created: 			23 September 2002
# Whom: 				pandzilla
#
# $FreeBSD$
#

PORTNAME=	nikto
PORTVERSION=	1.35
CATEGORIES=	security www
MASTER_SITES=	http://www.cirt.net/nikto/ \
		ftp://ftp.bay13.net/pub/wiretapped/vulnerability-assessment/nikto/ \
		http://mirror1.internap.com/pub/localareasecurity/wiretapped/vulnerability-assessment/nikto/ \
		ftp://ftp.localareasecurity.com/pub/wiretapped/vulnerability-assessment/nikto/ \
		http://www.mirrors.wiretapped.net/security/vulnerability-assessment/nikto/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web and CGI vulnerability scanner with SSL support

NO_BUILD=	yes
USE_REINPLACE=	yes

PORTDOCS=	nikto_usage.txt nikto_usage.html CHANGES.txt README_plugins.txt

post-patch:
	@${REINPLACE_CMD} -Ee 's,(config.txt),${PREFIX}/etc/nikto/\1,g' ${WRKSRC}/nikto.pl
	@${REINPLACE_CMD} -Ee "s|/usr/bin/nmap|${PREFIX}/bin/nmap|g" \
		-e "s|# (PLUGINDIR=)/usr/local/nikto/plugins|\1${DATADIR}|g" \
		${WRKSRC}/config.txt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nikto.pl ${PREFIX}/bin/nikto
	@${MKDIR} ${PREFIX}/etc/nikto
	${INSTALL_DATA} ${WRKSRC}/config.txt ${PREFIX}/etc/nikto
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/plugins/* ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
