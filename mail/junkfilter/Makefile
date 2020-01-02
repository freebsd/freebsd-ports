# Created by: Gregory Sutter <gsutter@zer0.org>
# $FreeBSD$

PORTNAME=	junkfilter
PORTVERSION=	20030115
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF \
		http://junkfilter.zer0.org/pkg/${PORTVERSION}/

MAINTAINER=	gsutter@zer0.org
COMMENT=	Spam filtering software for procmail

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	procmail:mail/procmail

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
BINDIR=		${PREFIX}/etc/${PORTNAME}
NO_ARCH=	yes

PORTSCOUT=	limit:^20

JFFILES=	LICENSE Makefile README TODO addresses bodychk dialups \
		headers ip jf jf-addresses jf-bodychk jf-dialups jf-domains \
		jf-headers jf-ip jf-white junkfilter junkfilter.bodychk \
		junkfilter.config junkfilter.four junkfilter.lists \
		junkfilter.match junkfilter.one junkfilter.opt \
		junkfilter.stats junkfilter.three junkfilter.two \
		junkfilter.user-default junkfilter.white procmailrc.sample \
		white

JFDOMFILES=	general

do-install:
	${MKDIR} ${STAGEDIR}${BINDIR}/domains
.for FILE in ${JFFILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${BINDIR}
.endfor
.for FILE in ${JFDOMFILES}
	${INSTALL_DATA} ${WRKSRC}/domains/${FILE} ${STAGEDIR}${BINDIR}/domains
.endfor

.include <bsd.port.mk>
