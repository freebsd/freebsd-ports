# New ports collection makefile for:	spamcalc
# Date created:			13 August 2002
# Whom:				Harold Gutch <logix@foobar.franken.de>
#
# $FreeBSD$

PORTNAME=	spamcalc
PORTVERSION=	0.5
CATEGORIES=	misc
MASTER_SITES=	http://www.garion.org/spamcalc/
DISTNAME=	sc-0.5
EXTRACT_SUFX=	.tgz

MAINTAINER=	logix@foobar.franken.de
COMMENT=	Calculates "DNS-spam"-values for hostnames

USE_PERL5=	YES

do-build:
	${REINPLACE_CMD} -e "s,sc.conf,${PREFIX}/etc/spamcalc.conf," \
		${WRKSRC}/sc.pl
	${REINPLACE_CMD} -e "s,datafilesdir.*,datafilesdir = ${DATADIR}," \
		${WRKSRC}/sc.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sc.pl ${PREFIX}/bin/spamcalc
	${INSTALL_DATA} ${WRKSRC}/sc.conf ${PREFIX}/etc/spamcalc.conf
	${MKDIR} ${DATADIR}
.for i in words regexps domains
	${INSTALL_DATA} ${WRKSRC}/${i} ${DATADIR}
.endfor
	${MKDIR} ${DATADIR}/data
.for i in domains.blacklist domains.whitelist regexps.general regexps.nonspam spam.txt words.de words.it words.negative words.nl words.pl words.swear words.template words.uk
	${INSTALL_DATA} ${WRKSRC}/data/${i} ${DATADIR}/data
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in LICENSE algorithms arguments feedback files introduction todo
	${INSTALL_MAN} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
