# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	Spreadsheet-ReadSXC
PORTVERSION=	0.24
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TERHECHTE
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Extract OpenOffice 1.x spreadsheet data

BUILD_DEPENDS=	p5-Archive-Zip>=1.34:archivers/p5-Archive-Zip \
		p5-XML-Parser>=0:textproc/p5-XML-Parser
RUN_DEPENDS=	p5-Archive-Zip>=1.34:archivers/p5-Archive-Zip \
		p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
