# New ports collection makefile for:	Spreadsheet::WriteExcel
# Date created:		25 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Spreadsheet-WriteExcel
PORTVERSION=	0.39
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Spreadsheet
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/OLE/Storage_Lite.pm:${PORTSDIR}/devel/p5-OLE-Storage_Lite \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip
RUN_DEPENDS=	${BUILD_DEPENDS}

PLIST_SUB=	DOCSDIR="share/doc/${PORTNAME}" \
		EXAMPLESDIR="share/examples/${PORTNAME}"
PERL_CONFIGURE=	yes

MAN3=		Spreadsheet::WriteExcel.3 \
		Spreadsheet::WriteExcel::BIFFwriter.3 \
		Spreadsheet::WriteExcel::Big.3 \
		Spreadsheet::WriteExcel::Format.3 \
		Spreadsheet::WriteExcel::Formula.3 \
		Spreadsheet::WriteExcel::OLEwriter.3 \
		Spreadsheet::WriteExcel::Utility.3 \
		Spreadsheet::WriteExcel::Workbook.3 \
		Spreadsheet::WriteExcel::WorkbookBig.3 \
		Spreadsheet::WriteExcel::Worksheet.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-configure:
	@${MV} ${WRKSRC}/WriteExcel/doc	${WRKSRC}
	@${MV} ${WRKSRC}/WriteExcel/examples	${WRKSRC}
	@${PERL} -pi -e 's:WriteExcel/(doc|examples):\1:g' \
		${WRKSRC}/MANIFEST

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README \
		${WRKSRC}/examples/republic.bmp ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
