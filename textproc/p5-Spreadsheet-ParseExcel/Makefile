# New ports collection makefile for:	Spreadsheet::ParseExcel
# Date created:		25 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Spreadsheet-ParseExcel
PORTVERSION=	0.2603
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Spreadsheet
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Get information from Excel file

BUILD_DEPENDS=	${SITE_PERL}/OLE/Storage_Lite.pm:${PORTSDIR}/devel/p5-OLE-Storage_Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"

MAN3=		Spreadsheet::ParseExcel.3 \
		Spreadsheet::ParseExcel::SaveParser.3 \
		Spreadsheet::ParseExcel::Utility.3

post-install:

.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}/Excel
	@${INSTALL_DATA} ${WRKSRC}/sample/README ${WRKSRC}/sample/res* \
		${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/sample/*.pl ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample/Excel/* ${EXAMPLESDIR}/Excel
.endif

.include <bsd.port.mk>
