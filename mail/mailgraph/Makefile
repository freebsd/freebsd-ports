# New ports collection makefile for:	mailgraph
# Date created:			30 August 2002
# Whom:				Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	mailgraph
PORTVERSION=	1.7
CATEGORIES=	mail
MASTER_SITES=	http://people.ee.ethz.ch/~dws/software/mailgraph/pub/ \
		http://people.ee.ethz.ch/~dws/software/mailgraph/pub/old/

MAINTAINER=	gslin@ccca.nctu.edu.tw
COMMENT=	A RRDtool frontend for Postfix statistics

RUN_DEPENDS=	${SITE_PERL}/RRDp.pm:${PORTSDIR}/net/rrdtool	\
		${SITE_PERL}/File/Tail.pm:${PORTSDIR}/devel/p5-File-Tail

NO_BUILD=	yes

STARTUP_SCRIPT=	mailgraph.sh.sample

post-patch:
	@${SED} -e "s,%%PREFIX%%,${PREFIX}," ${FILESDIR}/mailgraph.sh > ${WRKSRC}/${STARTUP_SCRIPT}

do-install:
	${MKDIR} ${PREFIX}/www/cgi-bin
.for FILE in mailgraph.cgi mailgraph.pl
	@${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/www/cgi-bin/
.endfor
	@${INSTALL_SCRIPT} ${WRKSRC}/${STARTUP_SCRIPT} ${PREFIX}/etc/rc.d/
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL}
	@${CHOWN} www:www ${PREFIX}/www/cgi-bin/

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
