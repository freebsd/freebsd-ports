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
PORTVERSION=	1.4.1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.logreport.org/pub/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Logfile analyse toolkit for multiple applications

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		\
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/MIME/Tools.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite

OPTIONS=	CHARTS "Have Charts output format" On \
		HTML "Have HTML or DocBook output format" On \
		PDF "Have PDF output format" Off \
		EXCEL95 "Have Excel95 Spreadsheey output format" Off
USE_GNOME=	libxml2 libxslt
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+="--with-docbookdir=${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd"

MAN1=		\
		argomail2dlf.1 bind8_named2dlf.1 bind8_query2dlf.1 \
		bind9_query2dlf.1 cisco_ios2dlf.1 combined2dlf.1 \
		common2dlf.1 cups_pagelog2dlf.1 dbmail2dlf.1 \
		exim2dlf.1 fw1_lea2dlf.1 iptables2dlf.1 isdnlog2dlf.1 \
		lprng_account2dlf.1 lr_anondump.1 lr_anonymize.1 \
		lr_check_prereq.1 lr_check_service.1 \
		lr_check_superservice.1 lr_config.1 lr_cron.1 \
		lr_deanonymize.1 lr_desyslog.1 lr_dlf2xml.1 lr_env.1 \
		lr_env2conf.1 lr_environment.1 lr_getbody.1 \
		lr_inflate.1 lr_log2mail.1 lr_log2report.1 lr_log2xml.1 \
		lr_mail.1 lr_rawmail2mail.1 lr_run.1 lr_setup_responder.1 \
		lr_spool.1 lr_spoold.1 lr_store.1 lr_vendor_cron.1 \
		lr_xml2ascii.1 lr_xml2chart.1 lr_xml2dbx.1 lr_xml2html.1 \
		lr_xml2mail.1 lr_xml2pdf.1 lr_xml2report.1 \
		lr_xml2xhtml.1 lr_xml2xls.1 lr_xml_merge.1 lr_xslt.1 \
		modgzip2dlf.1 ms_isa2dlf.1 mysql2dlf.1 nms2dlf.1 \
		nmsmmp2dlf.1 nmsstore2dlf.1 pgsql2dlf.1 pix2dlf.1 \
		postfix2dlf.1 postfix2dlf_main.1 postfix2dlf_pre.1 \
		qmail2dlf.1 referer2dlf.1 s1ms2dlf.1 sendmail2dlf.1 \
		snort2dlf.1 spamassassin2dlf.1 syslog2dlf.1 \
		tinydns2dlf.1 w3c_extended2dlf.1 welf2dlf.1 \
		welf_proxy2dlf.1 xferlog2dlf.1 lr_xml2rtf.1

MAN3=		\
		Lire::Aggregate.3pm Lire::Aggregator.3pm Lire::Apache.3pm \
		Lire::AsciiDlf::Aggregator.3pm Lire::AsciiDlf::DlfInfo.3pm \
		Lire::AsciiDlf::Group.3pm \
		Lire::AsciiDlf::ReportOperator.3pm Lire::Average.3pm \
		Lire::Config.3pm Lire::Config::Build.3pm \
		Lire::Config::Legacy.3pm Lire::Config::Parser.3pm \
		Lire::Config::Spec.3pm Lire::Config::SpecParser.3pm \
		Lire::Config::Values.3pm Lire::Count.3pm \
		Lire::DataTypes.3pm Lire::DlfConverter.3pm \
		Lire::DlfConverterManager.3pm Lire::DlfConverterProcess.3pm \
		Lire::DlfQuery.3pm Lire::DlfResult.3pm Lire::DlfSchema.3pm \
		Lire::DlfStore.3pm Lire::DlfStream.3pm Lire::Email.3pm \
		Lire::Field.3pm Lire::Firewall.3pm Lire::First.3pm \
		Lire::Group.3pm Lire::GroupField.3pm Lire::Last.3pm \
		Lire::LogSource.3pm Lire::Logger.3pm Lire::Max.3pm \
		Lire::Min.3pm Lire::OldDlfAdapter.3pm Lire::Program.3pm \
		Lire::Rangegroup.3pm Lire::Records.3pm Lire::Report.3pm \
		Lire::Report::ColumnInfo.3pm Lire::Report::Entry.3pm \
		Lire::Report::Group.3pm Lire::Report::GroupInfo.3pm \
		Lire::Report::Image.3pm Lire::Report::Note.3pm \
		Lire::Report::Section.3pm Lire::Report::Subreport.3pm \
		Lire::Report::TableInfo.3pm Lire::ReportGenerator.3pm \
		Lire::ReportMerger.3pm Lire::ReportOperator.3pm \
		Lire::ReportParser.3pm Lire::ReportParser::AsciiWriter.3pm \
		Lire::ReportParser::ChartWriter.3pm \
		Lire::ReportParser::DocBookFormatter.3pm \
		Lire::ReportParser::ExcelWriter.3pm \
		Lire::ReportParser::PloticusChartWriter.3pm \
		Lire::ReportParser::ReportBuilder.3pm \
		Lire::ReportParser::RowColHandler.3pm \
		Lire::SQLExt::LrCountUniq.3pm Lire::SQLExt::LrFirst.3pm \
		Lire::SQLExt::LrLast.3pm Lire::SQLExt::LrMatch.3pm \
		Lire::SQLExt::LrMissingCases.3pm \
		Lire::SQLExt::LrRangegroup.3pm \
		Lire::SQLExt::LrTimegroup.3pm Lire::SQLExt::LrTimeslot.3pm \
		Lire::SQLExt::Registry.3pm Lire::Sum.3pm Lire::Syslog.3pm \
		Lire::Test::CommandResult.3pm \
		Lire::Test::DlfConverterTestCase.3pm \
		Lire::Test::FunctionalTestCase.3pm \
		Lire::Test::HashConfig.3pm Lire::Test::TestCase.3pm \
		Lire::Time.3pm Lire::Timegroup.3pm Lire::Timeslot.3pm \
		Lire::Utils.3pm Lire::W3CExtendedLog.3pm Lire::WELF.3pm \
		Lire::WWW::Domain.3pm Lire::WWW::Filename.3pm \
		Lire::WWW::URL.3pm Lire::WWW::UserAgent.3pm \
		Lire::WeekCalculator.3pm Time::Timezone.3pm \

MAN7=		lire.7

.include <bsd.port.pre.mk>

.ifdef(WITH_CHARTS)
RUN_DEPENDS+=	pl:${PORTSDIR}/math/ploticus-nox11 \
		dia:${PORTSDIR}/graphics/dia
BUILD_DEPENDS+=	${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph
.endif
.ifdef(WITH_HTML)
RUN_DEPENDS+=	lynx:${PORTSDIR}/www/lynx
.endif
.ifdef(WITH_PDF)
RUN_DEPENDS+=	epsffit:${PORTSDIR}/print/psutils-a4 \
		gs:${PORTSDIR}/print/ghostview \
		jade:${PORTSDIR}/textproc/jade
.endif
.ifdef(WITH_EXCEL95)
BUILD_DEPENDS+=	${SITE_PERL}/Spreadsheet/WriteExcel.pm:${PORTSDIR}/textproc/p5-Spreadsheet-WriteExcel
.endif

RUN_DEPENDS+=	${BUILD_DEPENDS}

pdf:
	@${ECHO} "If you want to have PDF output, install print/teTeX first."
	@${ECHO} "Then, symlink ${LOCALBASE}/bin/pdftex to ${LOCALBASE}/bin/pdfjadetex:"
	@${ECHO} "    ln -fs ${LOCALBASE}/bin/pdftex ${LOCALBASE}/bin/pdfjadetex"
	@${ECHO} "As last, in ${LOCALBASE}/share/texmf/web2c/texmf.cnf,"
	@${ECHO} "increase the poolsize of pdfjadetex:"
	@${ECHO} "    pool_size.pdfjadetex = 500000"

post-install:
	@${CAT} pkg-message

.include <bsd.port.post.mk>
