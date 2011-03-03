# New ports collection makefile for:	xmltv
# Date created:		Mon Nov 4 02:56:34 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmltv
PORTVERSION=	0.5.59
CATEGORIES=	textproc perl5
MASTER_SITES=	SF
PKGNAMEPREFIX=	p5-

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Set of programs to process TV (tvguide) listings in XML format

XMLTV_DEPENDS=	\
	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
	${SITE_PERL}/XML/Twig.pm:${PORTSDIR}/textproc/p5-XML-Twig \
	${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer \
	${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
	${SITE_PERL}/${PERL_ARCH}/PerlIO/gzip.pm:${PORTSDIR}/archivers/p5-PerlIO-gzip \
	${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
	${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-IO-Compress \
	${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper \
	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
	${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
	${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
	${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
	${SITE_PERL}/${PERL_ARCH}/Tk/TableMatrix.pm:${PORTSDIR}/x11-toolkits/p5-Tk-TableMatrix \
	${SITE_PERL}/${PERL_ARCH}/Text/Kakasi.pm:${PORTSDIR}/japanese/p5-Text-Kakasi \
	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
	${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite \
	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
	${SITE_PERL}/HTML/TableExtract.pm:${PORTSDIR}/www/p5-HTML-TableExtract \
	${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
	${SITE_PERL}/Term/ProgressBar.pm:${PORTSDIR}/devel/p5-Term-ProgressBar \
	${SITE_PERL}/Lingua/Preferred.pm:${PORTSDIR}/textproc/p5-Lingua-Preferred \
	${SITE_PERL}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String \
	${SITE_PERL}/Unicode/UTF8simple.pm:${PORTSDIR}/converters/p5-Unicode-UTF8simple \
	${SITE_PERL}/Lingua/EN/Numbers/Ordinate.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Numbers-Ordinate \
	${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
	${SITE_PERL}/HTTP/Cache/Transparent.pm:${PORTSDIR}/www/p5-HTTP-Cache-Transparent \
	${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
	${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate
BUILD_DEPENDS=	${XMLTV_DEPENDS}
RUN_DEPENDS=	${XMLTV_DEPENDS}

USE_BZIP2=	yes
PERL_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

.ifdef(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-noportdocs-patch-Makefile.PL
.else
PORTDOCS=	COPYING \
		QuickStart \
		README \
		README.tv_check \
		README.win32 \
		tv_check_doc.html \
		tv_check_doc.jpg
.endif

MAN1=	tv_cat.1 tv_check.1 tv_extractinfo_ar.1 tv_extractinfo_en.1 \
	tv_find_grabbers.1 \
	tv_grab_ch_search.1 tv_grab_combiner.1 tv_grab_dk_dr.1 \
	tv_grab_dtv_la.1 tv_grab_ee.1 tv_grab_es_laguiatv.1 \
	tv_grab_es_miguiatv.1 tv_grab_fi.1 tv_grab_fi_sv.1 tv_grab_fr.1 tv_grab_hr.1 \
	tv_grab_huro.1 tv_grab_il.1 tv_grab_in.1 tv_grab_it.1 tv_grab_it_dvb.1 \
	tv_grab_is.1 tv_grab_na_dd.1 tv_grab_na_icons.1 tv_grab_nl.1 \
	tv_grab_no_gfeed.1 tv_grab_pt.1 tv_grab_pt_meo.1 tv_grab_re.1 tv_grab_se_swedb.1 \
	tv_grab_uk_bleb.1 tv_grab_uk_rt.1 tv_grab_za.1 tv_grep.1 tv_imdb.1 \
	tv_remove_some_overlapping.1 tv_sort.1 tv_split.1 tv_to_latex.1 \
	tv_to_potatoe.1 tv_to_text.1 tv_validate_file.1 \
	tv_validate_grabber.1 tv_grab_eu_epgdata.1 tv_grab_na_dtv.1
MAN3=	Configure.3 Configure::Writer.3 Lineup.3 Options.3 PreferredMethod.3 \
	ValidateFile.3 ValidateGrabber.3 Version.3 \
	XMLTV.3 XMLTV::Date.3 XMLTV::Grab_XML.3 XMLTV::Gunzip.3 \
	XMLTV::GUI.3 XMLTV::Summarize.3 XMLTV::Supplement.3

# idea taken from devel/cvsweb port
# Specify these directories in relative paths to ${PREFIX}.
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
ICONSDIR?=	share/apache/icons
.else
CGIDIR?=	www/cgi-bin
ICONSDIR?=	www/icons
.endif
#
PLIST_SUB+=	CGIDIR="${CGIDIR}"

post-patch:
# fix man install location
	@${REINPLACE_CMD} -e \
		's|share/man|man|' \
		${WRKSRC}/Makefile.PL
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} \
		-e 's|/usr/bin/perl|${PERL}|'
	@${FIND} ${WRKSRC} -type f \
		-name "*.bak" | \
		${XARGS} -n 10 ${RM}

post-install:
	@${MKDIR} ${PREFIX}/${CGIDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/choose/tv_pick/tv_pick_cgi ${PREFIX}/${CGIDIR}/tv_pick.cgi

.include <bsd.port.mk>
