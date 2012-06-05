# New ports collection makefile for:	bruteforceblocker
# Date created:				20 April 2005
# Whom:					Daniel Gerzo <danger@rulez.sk>
#
# $FreeBSD$
#

PORTNAME=	bruteforceblocker
PORTVERSION=	1.2.3
CATEGORIES=	security
MASTER_SITES=	http://danger.rulez.sk/projects/bruteforceblocker/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav

MAINTAINER=	danger@FreeBSD.org
COMMENT=	Checks for SSH bruteforce and blocks given IPs

RUN_DEPENDS=	p5-Unix-Syslog>=0:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		p5-Sys-Hostname-Long>=0:${PORTSDIR}/sysutils/p5-Sys-Hostname-Long \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS

NO_BUILD=	yes
USE_PERL5_RUN=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/sbin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf-dist
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in INSTALL CHANGELOG CREDITS
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
		${CP} -p ${PREFIX}/etc/${PORTNAME}.conf-dist ${PREFIX}/etc/${PORTNAME}.conf ; \
	fi
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
