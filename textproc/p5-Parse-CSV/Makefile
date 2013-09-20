# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	Parse-CSV
PORTVERSION=	2.00
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Highly flexible CVS parser for large files

BUILD_DEPENDS=	p5-Params-Util>=0.22:${PORTSDIR}/devel/p5-Params-Util \
		p5-Text-CSV_XS>=0.42:${PORTSDIR}/textproc/p5-Text-CSV_XS
RUN_DEPENDS=	p5-Params-Util>=0.22:${PORTSDIR}/devel/p5-Params-Util \
		p5-Text-CSV_XS>=0.42:${PORTSDIR}/textproc/p5-Text-CSV_XS

USES=		perl5
USE_PERL5=	configure

MAN3=		Parse::CSV.3

NO_STAGE=	yes
.include <bsd.port.mk>
