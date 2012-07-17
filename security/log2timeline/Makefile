# New ports collection makefile for:	log2timeline
# Date created:	24 December 2010
# Whom:		Nobutaka Mantani <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	log2timeline
PORTVERSION=	0.64
CATEGORIES=	security
MASTER_SITES=	http://log2timeline.net/files/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A log file parser for computer forensic investigations

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Carp-Assert>=0:${PORTSDIR}/devel/p5-Carp-Assert \
		p5-Data-Hexify>=0:${PORTSDIR}/devel/p5-Data-Hexify \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-DateTime-TimeZone>=0:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Mac-PropertyList>=0:${PORTSDIR}/devel/p5-Mac-PropertyList \
		p5-Parse-Win32Registry>=0:${PORTSDIR}/devel/p5-Parse-Win32Registry \
		p5-Image-ExifTool>=0:${PORTSDIR}/graphics/p5-Image-ExifTool \
		p5-Net-Pcap>=0:${PORTSDIR}/net/p5-Net-Pcap \
		p5-NetPacket>=0:${PORTSDIR}/net/p5-NetPacket \
		p5-Digest-CRC>=0:${PORTSDIR}/security/p5-Digest-CRC \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-File-Mork>=0:${PORTSDIR}/www/p5-File-Mork \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Scrubber>=0:${PORTSDIR}/www/p5-HTML-Scrubber \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

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
	Log2t::input::iehistory.3 \
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
	Log2t::output::serialize.3 \
	Log2t::output::tab.3 \
	Parse::Evtx2.3 \
	Parse::Evtx2::Chunk.3

.include <bsd.port.mk>
