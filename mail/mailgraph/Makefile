# New ports collection makefile for:	mailgraph
# Date created:			30 August 2002
# Whom:				Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	mailgraph
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://people.ee.ethz.ch/~dws/software/mailgraph/pub/

MAINTAINER=	gslin@ccca.nctu.edu.tw

NO_BUILD=	yes
NO_STRIP=	yes

RUN_DEPENDS=	${SITE_PERL}/RRDs.pm:${PORTSDIR}/net/rrdtool	\
		${SITE_PERL}/File/Tail.pm:${PORTSDIR}/devel/p5-File-Tail

do-install:
.for FILE in mailgraph.cgi mailgraph.pl
	@${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/www/cgi-bin/
.endfor

.include <bsd.port.mk>
