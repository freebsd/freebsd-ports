# New ports collection makefile for:	p5-Parse-CSV
# Date created:		2006-10-19
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Parse-CSV
PORTVERSION=	1.00
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Highly flexible CVS parser for large files

RUN_DEPENDS=	p5-Text-CSV_XS>=0.23:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-Params-Util>=0.17:${PORTSDIR}/devel/p5-Params-Util

PERL_CONFIGURE=	yes

MAN3=	Parse::CSV.3

.include <bsd.port.mk>
