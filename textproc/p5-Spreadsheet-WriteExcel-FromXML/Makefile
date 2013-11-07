# Created by: Bill Swingle <unfurl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Spreadsheet-WriteExcel-FromXML
PORTVERSION=	1.1
PORTEPOCH=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create an Excel Spreadsheet from XML

BUILD_DEPENDS=	p5-OLE-Storage_Lite>=0:${PORTSDIR}/devel/p5-OLE-Storage_Lite \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-Spreadsheet-WriteExcel>=0:${PORTSDIR}/textproc/p5-Spreadsheet-WriteExcel
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
