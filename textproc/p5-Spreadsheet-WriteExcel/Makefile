# New ports collection makefile for:	Spreadsheet::WriteExcel
# Date created:		25 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Spreadsheet-WriteExcel
PORTVERSION=	2.04
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Spreadsheet
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Write to a cross-platform Excel binary file

BUILD_DEPENDS=	${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${SITE_PERL}/OLE/Storage_Lite.pm:${PORTSDIR}/devel/p5-OLE-Storage_Lite \
		${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip
RUN_DEPENDS=	${BUILD_DEPENDS}

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.p[lm]"| \
	${XARGS} ${PERL} -pi -e 's/\x0D(?=\x0A)//g'

.if ${PERL_LEVEL} < 500600
post-configure:
# dirty hack to deceive irritable pod2man
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile
.endif

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

.include <bsd.port.post.mk>
