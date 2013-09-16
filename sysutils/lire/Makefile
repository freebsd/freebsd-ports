# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

#
# Remark regarding the errors during pkg_delete: These directories not
# there if you install from the package. They are generated when
# you install lire from the ports-collection.
#

PORTNAME=	lire
PORTVERSION=	2.1
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://download.logreport.org/pub/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Logfile analyse toolkit for multiple applications

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		lambda:${PORTSDIR}/math/lambda \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-Time-modules>=0:${PORTSDIR}/devel/p5-Time-modules \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-Curses>=0:${PORTSDIR}/devel/p5-Curses \
		p5-Curses-UI>=0:${PORTSDIR}/devel/p5-Curses-UI \
		p5-Locale-libintl>=0:${PORTSDIR}/devel/p5-Locale-libintl

OPTIONS_DEFINE=	CHARTS HTML PDF EXCEL95
OPTIONS_DEFAULT=	CHARTS HTML
CHARTS_DESC=	Have Charts output format
HTML_DESC=	Have HTML or DocBook output format
PDF_DESC=	Have PDF output format
EXCEL95_DESC=	Have Excel95 Spreadsheet output format

USES=		gmake perl5
USE_GNOME=	libxml2 libxslt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-docbookdir=${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd"
CONFIGURE_ENV=	POD2MAN=${LOCALBASE}/bin/pod2man

MAN1=		\
		argomail2dlf.1 \
		bind8_named2dlf.1 \
		bind8_query2dlf.1 \
		bind9_query2dlf.1 \
		cisco_ios2dlf.1 \
		combined2dlf.1 \
		common2dlf.1 \
		dbmail2dlf.1 \
		exim2dlf.1 \
		fw1_lea2dlf.1 \
		isdnlog2dlf.1 \
		lire.1 \
		lr_anondump.1 \
		lr_anonymize.1 \
		lr_check_service.1 \
		lr_check_superservice.1 \
		lr_cron.1 \
		lr_deanonymize.1 \
		lr_desyslog.1 \
		lr_env.1 \
		lr_environment.1 \
		lr_getbody.1 \
		lr_log2mail.1 \
		lr_log2report.1 \
		lr_mail.1 \
		lr_processmail.1 \
		lr_rawmail2mail.1 \
		lr_report_cfg2xml.1 \
		lr_run.1 \
		lr_setup_responder.1 \
		lr_spec2pot.1 \
		lr_spool.1 \
		lr_spoold.1 \
		lr_vendor_cron.1 \
		lr_xml2mail.1 \
		lr_xml2report.1 \
		modgzip2dlf.1 \
		ms_isa2dlf.1 \
		mysql2dlf.1 \
		nms2dlf.1 \
		nmsmmp2dlf.1 \
		nmsstore2dlf.1 \
		pgsql2dlf.1 \
		pix2dlf.1 \
		postfix2dlf.1 \
		postfix2dlf_main.1 \
		postfix2dlf_pre.1 \
		qmail2dlf.1 \
		referer2dlf.1 \
		s1ms2dlf.1 \
		sendmail2dlf.1 \
		snort2dlf.1 \
		spamassassin2dlf.1 \
		syslog2dlf.1 \
		tinydns2dlf.1 \
		w3c_extended2dlf.1 \
		welf2dlf.1 \
		welf_proxy2dlf.1 \
		xferlog2dlf.1

MAN3=		\
		Lire::Aggregate.3pm \
		Lire::Aggregator.3pm \
		Lire::Average.3pm \
		Lire::ChartType.3pm \
		Lire::ChartTypes::Dist.3pm \
		Lire::ChartTypes::Lines.3pm \
		Lire::ChartTypes::Pie.3pm \
		Lire::ChartTypes::Scat.3pm \
		Lire::ChartTypes::Stack.3pm \
		Lire::ChartTypes::VBars.3pm \
		Lire::Config.3pm \
		Lire::Config::BasePluginSpec.3pm \
		Lire::Config::Build.3pm \
		Lire::Config::ChartSpec.3pm \
		Lire::Config::ChartTypeSpec.3pm \
		Lire::Config::ConfigFile.3pm \
		Lire::Config::Dictionary.3pm \
		Lire::Config::DlfAnalyserSpec.3pm \
		Lire::Config::DlfConverterSpec.3pm \
		Lire::Config::DlfStreamSpec.3pm \
		Lire::Config::DlfStreamsSpec.3pm \
		Lire::Config::Index.3pm \
		Lire::Config::List.3pm \
		Lire::Config::Object.3pm \
		Lire::Config::OutputFormatSpec.3pm \
		Lire::Config::Parser.3pm \
		Lire::Config::Plugin.3pm \
		Lire::Config::RecordSpec.3pm \
		Lire::Config::Reference.3pm \
		Lire::Config::ReferenceSpec.3pm \
		Lire::Config::ReportConfigIndex.3pm \
		Lire::Config::ReportSectionSpec.3pm \
		Lire::Config::ReportSpec.3pm \
		Lire::Config::Scalar.3pm \
		Lire::Config::SpecParser.3pm \
		Lire::Config::Value.3pm \
		Lire::Config::VariableIndex.3pm \
		Lire::Config::XMLSpecListSpec.3pm \
		Lire::Count.3pm \
		Lire::DataTypes.3pm \
		Lire::DerivedSchema.3pm \
		Lire::DlfAnalyser.3pm \
		Lire::DlfAnalyserProcess.3pm \
		Lire::DlfCategoriser.3pm \
		Lire::DlfConverter.3pm \
		Lire::DlfConverterProcess.3pm \
		Lire::DlfQuery.3pm \
		Lire::DlfResult.3pm \
		Lire::DlfSchema.3pm \
		Lire::DlfStore.3pm \
		Lire::DlfStream.3pm \
		Lire::DocBookParser.3pm \
		Lire::Error.3pm \
		Lire::ExtendedSchema.3pm \
		Lire::Field.3pm \
		Lire::FilterExpr.3pm \
		Lire::FilterSpec.3pm \
		Lire::Firewall.3pm \
		Lire::Firewall::FortigateDlfConverter.3pm \
		Lire::Firewall::IpchainsDlfConverter.3pm \
		Lire::Firewall::IpfilterDlfConverter.3pm \
		Lire::Firewall::IptablesDlfConverter.3pm \
		Lire::Firewall::SnortDlfConverter.3pm \
		Lire::Firewall::WatchguardDlfConverter.3pm \
		Lire::First.3pm \
		Lire::Ftp::IisFtpDlfConverter.3pm \
		Lire::Group.3pm \
		Lire::GroupField.3pm \
		Lire::I18N.3pm \
		Lire::ImportJob.3pm \
		Lire::Last.3pm \
		Lire::Logger.3pm \
		Lire::LrCommand.3pm \
		Lire::Max.3pm \
		Lire::Min.3pm \
		Lire::OldDlfAdapter.3pm \
		Lire::OutputFormat.3pm \
		Lire::OutputFormats::DVI.3pm \
		Lire::OutputFormats::Excel95.3pm \
		Lire::OutputFormats::HTML.3pm \
		Lire::OutputFormats::LaTeX.3pm \
		Lire::OutputFormats::PDF.3pm \
		Lire::OutputFormats::PS.3pm \
		Lire::OutputFormats::Text.3pm \
		Lire::OutputFormats::XML.3pm \
		Lire::OutputJob.3pm \
		Lire::Param.3pm \
		Lire::Plugin.3pm \
		Lire::PluginManager.3pm \
		Lire::Program.3pm \
		Lire::Proxy::SquidAccessDlfConverter.3pm \
		Lire::Rangegroup.3pm \
		Lire::Records.3pm \
		Lire::Report.3pm \
		Lire::Report::ChartConfig.3pm \
		Lire::Report::ColumnInfo.3pm \
		Lire::Report::Entry.3pm \
		Lire::Report::Group.3pm \
		Lire::Report::GroupInfo.3pm \
		Lire::Report::Section.3pm \
		Lire::Report::Subreport.3pm \
		Lire::Report::TableInfo.3pm \
		Lire::ReportConfig.3pm \
		Lire::ReportJob.3pm \
		Lire::ReportOperator.3pm \
		Lire::ReportParser.3pm \
		Lire::ReportParser::AsciiDocBookFormatter.3pm \
		Lire::ReportParser::AsciiWriter.3pm \
		Lire::ReportParser::ExcelWriter.3pm \
		Lire::ReportParser::HTMLDocBookFormatter.3pm \
		Lire::ReportParser::HTMLWriter.3pm \
		Lire::ReportParser::LaTeXDocBookFormatter.3pm \
		Lire::ReportParser::LaTeXWriter.3pm \
		Lire::ReportParser::ReportBuilder.3pm \
		Lire::ReportParser::RowColHandler.3pm \
		Lire::ReportSchedule.3pm \
		Lire::ReportSection.3pm \
		Lire::ReportSpec.3pm \
		Lire::SQLExt::LrCountUniq.3pm \
		Lire::SQLExt::LrFirst.3pm \
		Lire::SQLExt::LrLast.3pm \
		Lire::SQLExt::LrMatch.3pm \
		Lire::SQLExt::LrMissingCases.3pm \
		Lire::SQLExt::LrRangegroup.3pm \
		Lire::SQLExt::LrTimegroup.3pm \
		Lire::SQLExt::LrTimeslot.3pm \
		Lire::SQLExt::Registry.3pm \
		Lire::Sum.3pm \
		Lire::Syslog.3pm \
		Lire::Test::CommandResult.3pm \
		Lire::Test::CursesUIDriver.3pm \
		Lire::Test::DlfAnalyserTestCase.3pm \
		Lire::Test::DlfConverterTestCase.3pm \
		Lire::Test::FunctionalTestCase.3pm \
		Lire::Test::HashConfig.3pm \
		Lire::Test::Mock.3pm \
		Lire::Test::PluginTestCase.3pm \
		Lire::Test::TestCase.3pm \
		Lire::Time.3pm \
		Lire::Timegroup.3pm \
		Lire::Timeslot.3pm \
		Lire::UI.3pm \
		Lire::UI::Prefs.3pm \
		Lire::UI::Utils.3pm \
		Lire::UI::Widget.3pm \
		Lire::Utils.3pm \
		Lire::W3CExtendedLog.3pm \
		Lire::WELF.3pm \
		Lire::WeekCalculator.3pm \
		Lire::XMLParser.3pm \
		Lire::XMLSpecContainer.3pm \
		Lire::XMLSpecI18N.3pm \
		Lire::XMLSpecParser.3pm

MAN7=		lire.7

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCHARTS}
RUN_DEPENDS+=	ploticus:${PORTSDIR}/math/ploticus-nox11
BUILD_DEPENDS+=	p5-GD-Graph>=0:${PORTSDIR}/graphics/p5-GD-Graph
.endif
.if ${PORT_OPTIONS:MHTML}
RUN_DEPENDS+=	lynx:${PORTSDIR}/www/lynx
.endif
.if ${PORT_OPTIONS:MPDF}
RUN_DEPENDS+=	epsffit:${PORTSDIR}/print/psutils \
		gs:${PORTSDIR}/print/ghostview \
		jade:${PORTSDIR}/textproc/jade \
		jadetex:${PORTSDIR}/print/jadetex \
		${LOCALBASE}/share/sgml/docbook/dsssl:${PORTSDIR}/textproc/dsssl-docbook-modular

.endif
.if ${PORT_OPTIONS:MEXCEL95}
BUILD_DEPENDS+=	p5-Spreadsheet-WriteExcel>=0:${PORTSDIR}/textproc/p5-Spreadsheet-WriteExcel
.endif

RUN_DEPENDS+=	${BUILD_DEPENDS}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
