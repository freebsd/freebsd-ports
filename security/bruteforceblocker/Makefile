# Created by: Daniel Gerzo <danger@rulez.sk>
# $FreeBSD$

PORTNAME=	bruteforceblocker
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://danger.rulez.sk/projects/bruteforceblocker/ \
		LOCAL/pav

MAINTAINER=	danger@FreeBSD.org
COMMENT=	Checks for SSH bruteforce and blocks given IPs

RUN_DEPENDS=	p5-Unix-Syslog>=0:sysutils/p5-Unix-Syslog \
		p5-Sys-Hostname-Long>=0:sysutils/p5-Sys-Hostname-Long \
		p5-libwww>=0:www/p5-libwww \
		p5-Net-DNS>=0:dns/p5-Net-DNS

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message
SHEBANG_FILES=	${PORTNAME}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in INSTALL CHANGELOG CREDITS
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
