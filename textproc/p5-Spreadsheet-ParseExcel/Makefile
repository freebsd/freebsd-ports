# New ports collection makefile for:	Spreadsheet::ParseExcel
# Date created:		25 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Spreadsheet-ParseExcel
PORTVERSION=	0.2403
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Spreadsheet
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/OLE/Storage_Lite.pm:${PORTSDIR}/devel/p5-OLE-Storage_Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Spreadsheet::ParseExcel.3 \
		Spreadsheet::ParseExcel::Utility.3 \
		Spreadsheet::ParseExcel::SaveParser.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
