# New ports collection makefile for:	lire
# Date Created:				26 june 2002
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

#
# Remark regarding the errors during pkg_delete: These directories not
# there if you install from the package. They are generated when
# you install lire from the ports-collection.
#

PORTNAME=	lire
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://download.logreport.org/pub/archive/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Logfile analyse toolkit for multiple applications

LIB_DEPENDS=	\
	expat.4:${PORTSDIR}/textproc/expat2 \
	xml2.5:${PORTSDIR}/textproc/libxml2 \
	xslt.2:${PORTSDIR}/textproc/libxslt
BUILD_DEPENDS=	\
	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml \
	${LOCALBASE}/share/sgml/docbook/dsssl/modular/catalog:${PORTSDIR}/textproc/dsssl-docbook-modular \
	${LOCALBASE}/share/xsl/docbook/fo/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl \
	${ARCH_PERL}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
	${SITE_PERL}/Spreadsheet/WriteExcel.pm:${PORTSDIR}/textproc/p5-Spreadsheet-WriteExcel \
	${SITE_PERL}/Time/Timezone.pm:${PORTSDIR}/devel/p5-Time-modules \
	${SITE_PERL}/MIME/Entity.pm:${PORTSDIR}/mail/p5-MIME-Tools \
	${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+="--with-docbookdir=${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd"

ARCH_PERL=	${SITE_PERL}/${PERL_ARCH}

MAN1=		\
		lr_archive_log.1 lr_check_errlines.1	\
		lr_check_prereq.1 lr_config.1 lr_cron.1	\
		lr_db_fetch.1 lr_db_purge.1 lr_db_store.1	\
		lr_desyslog.1 lr_processmail.1 lr_rawmail2mail.1	\
		lr_run.1 lr_spool.1 lr_tag.1	\
		lr_xml2html.1 lr_xml2pdf.1 lr_xml2rtf.1	\
		lr_xml2logml.1 lr_xml2report.1 lr_xml2dbx.1	\
		lr_xml2xhtml.1 lr_xml2mail.1 lr_xslt.1	\
		lr_anondump.1 lr_anonymize.1 lr_check_service.1	\
		lr_check_superservice.1 lr_deanonymize.1	\
		lr_dlf_analyze.1 lr_dlf2xml.1 lr_dlf2sql.1	\
		lr_getbody.1 lr_inflate.1 lr_log2mail.1	\
		lr_log2report.1 lr_log2xml.1 lr_mail.1	\
		lr_prof_report.1 lr_spoold.1 lr_sql2dlf.1	\
		lr_sql2report.1 lr_xml2ascii.1 lr_xml_merge.1	\
		lr_xml2png.1 lr_xml2xls.1 bind8_query2dlf.1	\
		bind9_query2dlf.1 bind8_named2dlf.1 mysql2dlf.1	\
		pgsql2dlf.1 isdnlog2dlf.1 postfix2dlf.1	\
		argomail2dlf.1 exim2dlf.1 nms2dlf.1	\
		postfix2dlf_main.1 postfix2dlf_pre.1 qmail2dlf.1	\
		sendmail2dlf.1 cisco_ios2dlf.1 ipfilter2dlf.1	\
		ipchains2dlf.1 iptables2dlf.1 pix2dlf.1	\
		watchguard2dlf.1 welf2dlf.1 xferlog2dlf.1	\
		iis_ftp2dlf.1 nmsmmp2dlf.1 nmsstore2dlf.1	\
		cups_pagelog2dlf.1 lprng_account2dlf.1	\
		ms_isa2dlf.1 squid_access2dlf.1 welf_proxy2dlf.1	\
		syslog2dlf.1 combined2dlf.1 common2dlf.1	\
		modgzip2dlf.1 referer2dlf.1 w3c_extended2dlf.1

MAN3=		\
		Lire::ReportParser::AsciiWriter.3pm	\
		Lire::ReportParser::ChartWriter.3pm	\
		Lire::ReportParser::DocBookFormatter.3pm	\
		Lire::AsciiDlf::DlfInfo.3pm	\
		Lire::AsciiDlf::Group.3pm Lire::Report::Entry.3pm	\
		Lire::Report::Group.3pm Lire::Report::Image.3pm	\
		Lire::Report::Section.3pm	\
		Lire::Report::Subreport.3pm	\
		Lire::ReportParser::ExcelWriter.3pm	\
		Lire::ReportParser::ReportBuilder.3pm	\
		Lire::Field.3pm Lire::Report.3pm	\
		Lire::W3CExtendedLog.3pm Lire::WELF.3pm	\
		Lire::XMLUtils.3pm Lire::Syslog.3pm	\
		Lire::WWW::URL.3pm Lire::WWW::UserAgent.3pm	\
		Lire::WWW::Domain.3pm Lire::WWW::Filename.3pm	\
		Lire::Time.3pm Lire::Email.3pm	\
		Lire::DlfSchema.3pm Lire::Apache.3pm	\
		Lire::DataTypes.3pm Lire::Program.3pm	\
		Lire::ReportParser.3pm Lire::Firewall.3pm

pre-configure:
	@${ECHO} "PDF output is not enabled by default."
	@${ECHO} "Run 'make pdf' to see how to enable it."

pdf:
	@${ECHO} "If you want to have PDF output, install print/teTeX first."
	@${ECHO} "Then, symlink ${LOCALBASE}/bin/pdftex to ${LOCALBASE}/bin/pdfjadetex:"
	@${ECHO} "    ln -fs ${LOCALBASE}/bin/pdftex ${LOCALBASE}/bin/pdfjadetex"
	@${ECHO} "As last, in ${LOCALBASE}/share/texmf/web2c/texmf.cnf,"
	@${ECHO} "increase the poolsize of pdfjadetex:"
	@${ECHO} "    pool_size.pdfjadetex = 500000"

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
