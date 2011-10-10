# New ports collection makefile for:	log2timeline
# Date created:	24 December 2010
# Whom:		Nobutaka Mantani <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	log2timeline
PORTVERSION=	0.61
CATEGORIES=	security
MASTER_SITES=	http://log2timeline.net/files/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A log file parser for computer forensic investigations

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/${PERL_ARCH}/DBI/DBD.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Carp/Assert.pm:${PORTSDIR}/devel/p5-Carp-Assert \
		${SITE_PERL}/Data/Hexify.pm:${PORTSDIR}/devel/p5-Data-Hexify \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Format/Strptime.pm:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		${SITE_PERL}/DateTime/TimeZone.pm:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/Mac/PropertyList.pm:${PORTSDIR}/devel/p5-Mac-PropertyList \
		${SITE_PERL}/Parse/Win32Registry.pm:${PORTSDIR}/devel/p5-Parse-Win32Registry \
		${SITE_PERL}/Image/ExifTool.pm:${PORTSDIR}/graphics/p5-Image-ExifTool \
		${SITE_PERL}/${PERL_ARCH}/Net/Pcap.pm:${PORTSDIR}/net/p5-Net-Pcap \
		${SITE_PERL}/NetPacket.pm:${PORTSDIR}/net/p5-NetPacket \
		${SITE_PERL}/${PERL_ARCH}/Digest/CRC.pm:${PORTSDIR}/security/p5-Digest-CRC \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/File/Mork.pm:${PORTSDIR}/www/p5-File-Mork \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/HTML/Scrubber.pm:${PORTSDIR}/www/p5-HTML-Scrubber \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}

MAN1=	l2t_process.1 \
	log2timeline.1 \
	timescanner.1
MAN3=	Log2Timeline.3 \
	Log2t::BinRead.3 \
	Log2t::Numbers.3 \
	Log2t::Time.3 \
	Log2t::base::input.3 \
	Log2t::input::altiris.3 \
	Log2t::input::encase_dirlisting.3 \
	Log2t::input::evt.3 \
	Log2t::input::evtx.3 \
	Log2t::input::ff_bookmark.3 \
	Log2t::input::firefox2.3 \
	Log2t::input::ftk_dirlisting.3 \
	Log2t::input::jp_ntfs_change.3 \
	Log2t::input::mcafee.3 \
	Log2t::input::mcafeefireup.3 \
	Log2t::input::mcafeehel.3 \
	Log2t::input::mcafeehs.3 \
	Log2t::input::mft.3 \
	Log2t::input::mssql_errlog.3 \
	Log2t::input::opera.3 \
	Log2t::input::pcap.3 \
	Log2t::input::pdf.3 \
	Log2t::input::setupapi.3 \
	Log2t::input::sol.3 \
	Log2t::input::symantec.3 \
	Log2t::input::volatility.3 \
	Log2t::input::wmiprov.3 \
	Log2t::output::beedocs.3 \
	Log2t::output::cef.3 \
	Log2t::output::cftl.3 \
	Log2t::output::csv.3 \
	Log2t::output::tab.3 \
	Parse::Evtx.3 \
	Parse::Evtx::Chunk.3

.include <bsd.port.mk>
