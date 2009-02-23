# New ports collection makefile for:	p5-EBook-Tools
# Date created:		20 February 2009
# Whom:	      		simond@irrelevant.org
#
# $FreeBSD$
#

PORTNAME=	EBook-Tools
PORTVERSION=	0.4.3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	simond@irrelevant.org
COMMENT=	Object class for manipulating and generating E-books

BUILD_DEPENDS=	${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${SITE_PERL}/${PERL_ARCH}/Data/UUID.pm:${PORTSDIR}/devel/p5-Data-UUID \
		${SITE_PERL}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/File/MimeInfo.pm:${PORTSDIR}/devel/p5-File-MimeInfo \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash \
		${SITE_PERL}/Time/Local.pm:${PORTSDIR}/devel/p5-Time-Local \
		${SITE_PERL}/XML/Twig.pm:${PORTSDIR}/textproc/p5-XML-Twig \
		${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp \
		${SITE_PERL}/Palm/PDB.pm:${PORTSDIR}/palm/p5-Palm \
		${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
		${SITE_PERL}/${PERL_ARCH}/String/CRC32.pm:${PORTSDIR}/devel/p5-String-CRC32 \
		${SITE_PERL}/HTML/TextToHTML.pm:${PORTSDIR}/textproc/txt2html
RUN_DEPENDS+=	${LOCALBASE}/bin/tidy:${PORTSDIR}/www/tidy

PERL_CONFIGURE=	yes

MAN3=		EBook::Tools::Unpack.3 EBook::Tools::MSReader.3 EBook::Tools::LZSS.3 \
		EBook::Tools::Mobipocket.3 EBook::ebook.3 EBook::Tools::EReader.3 \
		EBook::Tools::IMP.3 EBook::Tools::PalmDoc.3 EBook::Tools.3

.include <bsd.port.mk>
