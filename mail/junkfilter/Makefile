# New ports collection makefile for:	junkfilter
# Date created:				20000523
# Whom:					Gregory Sutter <gsutter@zer0.org>

#
# $FreeBSD$
#

PORTNAME=	junkfilter
PORTVERSION=	20030115
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://junkfilter.zer0.org/pkg/${PORTVERSION}/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gsutter@zer0.org
COMMENT=	Spam filtering software for procmail

RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

NO_BUILD=	yes
BINDIR=		${PREFIX}/etc/${PORTNAME}

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
	${MKDIR} ${BINDIR}/domains
.for FILE in ${JFFILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${BINDIR}
.endfor
.for FILE in ${JFDOMFILES}
	${INSTALL_DATA} ${WRKSRC}/domains/${FILE} ${BINDIR}/domains
.endfor

.include <bsd.port.mk>
