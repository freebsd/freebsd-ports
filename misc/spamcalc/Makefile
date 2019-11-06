# Created by: Harold Gutch <logix@foobar.franken.de>
# $FreeBSD$

PORTNAME=	spamcalc
PORTVERSION=	0.5
CATEGORIES=	misc
MASTER_SITES=	http://www.garion.org/spamcalc/
DISTNAME=	sc-0.5

MAINTAINER=	logix@foobar.franken.de
COMMENT=	Calculates "DNS-spam"-values for hostnames

BROKEN=		unfetchable

USES=		perl5 tar:tgz

OPTIONS_DEFINE=	DOCS

do-build:
	${REINPLACE_CMD} -e "s,sc.conf,${PREFIX}/etc/spamcalc.conf," \
		${WRKSRC}/sc.pl
	${REINPLACE_CMD} -e "s,datafilesdir.*,datafilesdir = ${DATADIR}," \
		${WRKSRC}/sc.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sc.pl ${STAGEDIR}${PREFIX}/bin/spamcalc
	${INSTALL_DATA} ${WRKSRC}/sc.conf ${STAGEDIR}${PREFIX}/etc/spamcalc.conf
	${MKDIR} ${STAGEDIR}${DATADIR}
.for i in words regexps domains
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DATADIR}
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}/data
.for i in domains.blacklist domains.whitelist regexps.general regexps.nonspam \
	spam.txt words.de words.it words.negative words.nl words.pl \
	words.swear words.template words.uk
	${INSTALL_DATA} ${WRKSRC}/data/${i} ${STAGEDIR}${DATADIR}/data
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in LICENSE algorithms arguments feedback files introduction todo
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
