# New ports collection makefile for:	p5-Spreadsheet-ReadSXC
# Date created:		2010-03-08
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Spreadsheet-ReadSXC
PORTVERSION=	0.20
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TERHECHTE
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Extract OpenOffice 1.x spreadsheet data

BUILD_DEPENDS=	p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

PERL_CONFIGURE=	yes

MAN3=	Spreadsheet::ReadSXC.3

.include <bsd.port.mk>
