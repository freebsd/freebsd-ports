# New ports collection makefile for:	junkfilter
# Date created:				20000523
# Whom:					Gregory Sutter <gsutter@zer0.org>

#
# $Id: Makefile,v 1.5 2000/05/24 05:40:31 gsutter Exp $
#
# $FreeBSD$
#

PORTNAME=	junkfilter
PORTVERSION=	20000313
CATEGORIES=	mail
MASTER_SITES=	http://junkfilter.zer0.org/pkg/20000313/

MAINTAINER=	gsutter@zer0.org

RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

NO_BUILD=	yes
BINDIR=		${PREFIX}/etc/${PORTNAME}

JFFILES=	LICENSE addresses bodychk dialups headers ip jf jf-addresses \
		jf-addresses-user-default jf-bodychk jf-bodychk-user-default \
		jf-dialups jf-dialups-user-default jf-domains \
		jf-domains-user-default jf-headers jf-headers-user-default \
		jf-ip jf-ip-user-default jf-white junkfilter \
		junkfilter.bodychk junkfilter.config junkfilter.four \
		junkfilter.lists junkfilter.match junkfilter.one \
		junkfilter.opt junkfilter.readme junkfilter.three \
		junkfilter.two junkfilter.user-default junkfilter.white white

JFDOMFILES=	assorted general gulf-blocks harrismkt thehitman tsf-fannin

do-install:
	${MKDIR} ${BINDIR}/domains
.for FILE in ${JFFILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${BINDIR}
.endfor
.for FILE in ${JFDOMFILES}
	${INSTALL_DATA} ${WRKSRC}/domains/${FILE} ${BINDIR}/domains
.endfor

.include <bsd.port.mk>
