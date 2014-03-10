# Created by: sumikawa@FreeBSD.org
# $FreeBSD$

PORTNAME=	Plagger
PORTVERSION=	0.7.17
PORTREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Pluggable RSS/Atom feed aggregator written in Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-TimeZone>=0:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-DateTime-Locale>=0:${PORTSDIR}/devel/p5-DateTime-Locale \
		p5-DateTime-Format-Mail>=0:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-DateTime-Format-W3CDTF>=0:${PORTSDIR}/devel/p5-DateTime-Format-W3CDTF \
		p5-Cache>=0:${PORTSDIR}/devel/p5-Cache \
		p5-Cache-Cache>=0:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-File-Find-Rule>=0:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-Module-Install>=0:${PORTSDIR}/devel/p5-Module-Install \
		p5-Module-Pluggable-Fast>=0:${PORTSDIR}/devel/p5-Module-Pluggable-Fast \
		p5-Term-Encoding>=0:${PORTSDIR}/devel/p5-Term-Encoding \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-MIME-Types>=0:${PORTSDIR}/mail/p5-MIME-Types \
		p5-Text-Tags>=0:${PORTSDIR}/textproc/p5-Text-Tags \
		p5-XML-Feed>=0:${PORTSDIR}/textproc/p5-XML-Feed \
		p5-XML-RSS-LibXML>=0:${PORTSDIR}/textproc/p5-XML-RSS-LibXML \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Template-Provider-Encoding>=0:${PORTSDIR}/www/p5-Template-Provider-Encoding \
		p5-HTML-ResolveLink>=0:${PORTSDIR}/www/p5-HTML-ResolveLink \
		p5-URI-Fetch>=0:${PORTSDIR}/www/p5-URI-Fetch \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	assets/plugins/CustomFeed-Script/domain-expire.pl \
		assets/plugins/CustomFeed-Script/jsports-football.pl \
		assets/plugins/CustomFeed-Script/ssl-expire.pl \
		assets/plugins/CustomFeed-Script/slims_calendar.pl \
		assets/plugins/CustomFeed-Script/wowow-hv-51ch.pl \
		assets/plugins/CustomFeed-Script/wowow-liga-espanola.pl

OPTIONS_DEFINE=	AUTHORNAME BABELFISH BETTERENCODING BETTERHTML BLOGLINES \
		COOKIESHARING CUSFEEDMIXI CUSTOMSVNLOG EMOTICON ESTRAIER \
		FILDEGYT FILHATENA FILHATKTAG FILHTMLSCRB FILMRKDWN \
		FILSPAMASSN FILTERPIPE FILTERPPT FLICKRSEARCH GUESSLANG \
		GUESSTZ HATENABKMK HATENADIARY HATENARSS HTMLTIDY IMAGEINFO \
		JAVASCRIPT KINOSEARCH LIBERALXML LIVEDOOR \
		NOTIFYIRC NTFYNETSEND PALMDOC PINGSERVER PLANETINI PODTESTING \
		PROFANITY PRSJPNDATE PRSJPNDATE PUBDELICIOUS PUBICAL PUBJSON \
		PUBLISHCSV PUBLISHEXCEL PUBLISHGMAIL PUBLISHIMAP PUBLISHMT \
		PUBLISHPDF PUBLISHPLANET PUBLISHSWF PUBSERLZR ROMANIZE \
		RULEFRESH SRCHGREP SUBSCOPML SUBSCRDBI SUBSCRFOAF SUMJPN \
		SUMMARYENG SUMTEXTORG XPATH DOCS EXAMPLES

BETTERENCODING_DESC=	Better Encoding detection Support
PODTESTINGPOD_DESC=	Testing Support
COOKIESHARING_DESC=	Cookie sharing with Firefox Support
LIBERALXML_DESC=	Liberal XML parsing Support
XPATH_DESC=	XPath Support
BETTERHTML_DESC=	Better html to text formatter
PRSJPNDATE_DESC=	Parse Japanese datetime format
PUBLISHEXCEL_DESC=	Publish::Excel Support
FILTERPIPE_DESC=	Filter::Pipe Support
PUBLISHPLANET_DESC=	Publish::Planet Support
PUBLISHCSV_DESC=	Publish::CSV Support
FILDEGYT_DESC=	Filter-DegradeYouTube
AUTHORNAME_DESC=	Filter::ExtractAuthorName Support
GUESSLANG_DESC=	Filter::GuessLanguage Support
GUESSTZ_DESC=	Filter::GuessTimeZoneByDomain Support
HTMLTIDY_DESC=	Filter::HTMLTidy Support
PUBLISHMT_DESC=	Publish::MT Support
PUBSERLZR_DESC=	Publish-Serializer Support
PUBICAL_DESC=	Publish::iCal Support
ROMANIZE_DESC=	Filter::Romanize Support
JAVASCRIPT_DESC=	Publish::JavaScript Support
EMOTICON_DESC=	Filter::Emoticon Support
FILHATENA_DESC=	Filter::HatenaFormat Support
FILHATKTAG_DESC=	Filter::HatenaKeywordTag
RULEFRESH_DESC=	Rule::Fresh Support
SUBSCOPML_DESC=	Subscription::OPML Support
FLICKRSEARCH_DESC=	CustomFeed::FlickrSearch Support
HATENABKMK_DESC=	Filter::HatenaBookmarkUsersCount Support
PALMDOC_DESC=	Publish::PalmDoc Support
PUBLISHSWF_DESC=	Publish::SWF Support
SUBSCRDBI_DESC=	Subscription::DBI Support
FILTERPPT_DESC=	Filter::TTP Support
KINOSEARCH_DESC=	Search::KinoSearch Support
PUBLISHGMAIL_DESC=	Publish::Gmail Support
PUBDELICIOUS_DESC=	Publish::Delicious Support
ESTRAIER_DESC=	Search::Estraier Support
SRCHGREP_DESC=	Search::Grep
PUBJSON_DESC=	Publish::JSON Support
FILSPAMASSN_DESC=	Filter-SpamAssassin Support
PROFANITY_DESC=	Filter::Profanity Support
HATENARSS_DESC=	Subscription::HatenaRSS Support
SUBSCRFOAF_DESC=	Subscription::FOAF Support
NOTIFYIRC_DESC=	Notify::IRC Support
HATENADIARY_DESC=	Filter::HatenaDiaryKeywordLink Support
LIVEDOOR_DESC=	Subscription::LivedoorReader Support
PINGSERVER_DESC=	Subscription::PingServer Support
IMAGEINFO_DESC=	Filter::ImageInfo Support
FILMRKDWN_DESC=	Filter::Markdown Support
PUBLISHIMAP_DESC=	Publish::IMAP Support
PUBLISHPDF_DESC=	Publish::PDF Support
BLOGLINES_DESC=	Subscription::Bloglines Support
BABELFISH_DESC=	Filter::Babelfish Support
CUSFEEDMIXI_DESC=	CustomFeed::Mixi Support
CUSTOMSVNLOG_DESC=	CustomFeed::SVNLog Support
NTFYNETSEND_DESC=	Notify::NetSend Support
FILHTMLSCRB_DESC=	Filter::HTMLScrubber Support
PLANETINI_DESC=	Subscription::PlanetINI Support
SUMMARYENG_DESC=	Summary-English Support
SUMJPN_DESC=	Summary::Japanes
SUMTEXTORG_DESC=	Summary-TextOriginal Support

OPTIONS_DEFAULT=	BETTERENCODING LIBERALXML XPATH BETTERHTML \
			PUBLISHPLANET GUESSTZ EMOTICON RULEFRESH SUBSCOPML \
			SUBSCRDBI PUBLISHGMAIL HATENARSS SUBSCRFOAF LIVEDOOR \
			PINGSERVER BLOGLINES FILHTMLSCRB PLANETINI

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBETTERENCODING}
BUILD_DEPENDS+=	p5-Encode-Detect>=0:${PORTSDIR}/converters/p5-Encode-Detect
.endif

.if ${PORT_OPTIONS:MPODTESTING}
BUILD_DEPENDS+=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage
.endif

.if ${PORT_OPTIONS:MCOOKIESHARING}
BUILD_DEPENDS+=	p5-HTTP-Cookies-Mozilla>=0:${PORTSDIR}/www/p5-HTTP-Cookies-Mozilla
.endif

.if ${PORT_OPTIONS:MLIBERALXML}
BUILD_DEPENDS+=	p5-XML-Liberal>=0:${PORTSDIR}/textproc/p5-XML-Liberal  \
		p5-XML-RSS-Liberal>=0:${PORTSDIR}/textproc/p5-XML-RSS-Liberal
.endif

.if ${PORT_OPTIONS:MXPATH}
BUILD_DEPENDS+=	p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-HTML-Format>=0:${PORTSDIR}/textproc/p5-HTML-Format
.endif

.if ${PORT_OPTIONS:MBETTERHTML}
BUILD_DEPENDS+=	p5-HTML-TreeBuilder-XPath>=0:${PORTSDIR}/www/p5-HTML-TreeBuilder-XPath
.endif

.if ${PORT_OPTIONS:MPRSJPNDATE}
BUILD_DEPENDS+=	ja-p5-DateTime-Format-Japanese>=0:${PORTSDIR}/japanese/p5-DateTime-Format-Japanese
.endif

.if ${PORT_OPTIONS:MPUBLISHEXCEL}
BUILD_DEPENDS+=	p5-Spreadsheet-WriteExcel>=0:${PORTSDIR}/textproc/p5-Spreadsheet-WriteExcel
.endif

.if ${PORT_OPTIONS:MFILTERPIPE}
BUILD_DEPENDS+=	p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run
.endif

.if ${PORT_OPTIONS:MPUBLISHPLANET}
BUILD_DEPENDS+=	p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-HTML-Scrubber>=0:${PORTSDIR}/www/p5-HTML-Scrubber
.endif

.if ${PORT_OPTIONS:MPUBLISHCSV}
BUILD_DEPENDS+=	p5-Text-CSV>=0:${PORTSDIR}/textproc/p5-Text-CSV
.endif

.if ${PORT_OPTIONS:MFILDEGYT}
BUILD_DEPENDS+=	p5-WebService-YouTube>=0:${PORTSDIR}/www/p5-WebService-YouTube
.endif

.if ${PORT_OPTIONS:MAUTHORNAME}
BUILD_DEPENDS+=	p5-Email-Address>=0:${PORTSDIR}/mail/p5-Email-Address
.endif

.if ${PORT_OPTIONS:MGUESSLANG}
BUILD_DEPENDS+=	p5-Lingua-ZH-HanDetect>=0:${PORTSDIR}/chinese/p5-Lingua-ZH-HanDetect \
		p5-Text-Language-Guess>=0:${PORTSDIR}/textproc/p5-Text-Language-Guess
.endif

.if ${PORT_OPTIONS:MGUESSTZ}
BUILD_DEPENDS+=	p5-IP-Country>=0:${PORTSDIR}/net/p5-IP-Country
.endif

.if ${PORT_OPTIONS:MHTMLTIDY}
BUILD_DEPENDS+=	p5-HTML-Tidy>=0:${PORTSDIR}/textproc/p5-HTML-Tidy
.endif

.if ${PORT_OPTIONS:MPUBLISHMT}
BUILD_DEPENDS+=	p5-Net-MovableType>=0:${PORTSDIR}/net/p5-Net-MovableType
.endif

.if ${PORT_OPTIONS:MPUBSERLZR}
BUILD_DEPENDS+=	p5-Data-Serializer>=0:${PORTSDIR}/devel/p5-Data-Serializer
.endif

.if ${PORT_OPTIONS:MPUBICAL}
BUILD_DEPENDS+=	p5-Data-ICal>=0:${PORTSDIR}/deskutils/p5-Data-ICal \
		p5-DateTime-Format-ICal>=0:${PORTSDIR}/devel/p5-DateTime-Format-ICal
.endif

.if ${PORT_OPTIONS:MROMANIZE}
BUILD_DEPENDS+=	ja-p5-Text-Kakasi>=0:${PORTSDIR}/japanese/p5-Text-Kakasi
.endif

.if ${PORT_OPTIONS:MJAVASCRIPT}
BUILD_DEPENDS+=	p5-Template-Plugin-JavaScript>=0:${PORTSDIR}/www/p5-Template-Plugin-JavaScript
.endif

.if ${PORT_OPTIONS:MEMOTICON}
BUILD_DEPENDS+=	p5-Text-Emoticon>=0:${PORTSDIR}/textproc/p5-Text-Emoticon
.endif

.if ${PORT_OPTIONS:MFILHATENA}
BUILD_DEPENDS+=	p5-Text-Hatena>=0:${PORTSDIR}/textproc/p5-Text-Hatena
.endif

.if ${PORT_OPTIONS:MFILHATKTAG}
BUILD_DEPENDS+=	p5-Hatena-Keyword>=0:${PORTSDIR}/textproc/p5-Hatena-Keyword
.endif

.if ${PORT_OPTIONS:MRULEFRESH}
BUILD_DEPENDS+=	p5-Time-Duration-Parse>=0:${PORTSDIR}/devel/p5-Time-Duration-Parse
.endif

.if ${PORT_OPTIONS:MSUBSCOPML}
BUILD_DEPENDS+=	p5-XML-OPML>=0:${PORTSDIR}/textproc/p5-XML-OPML
.endif

.if ${PORT_OPTIONS:MFLICKRSEARCH}
BUILD_DEPENDS+=	p5-Flickr-API>=0:${PORTSDIR}/www/p5-Flickr-API \
		p5-DateTime-Format-Epoch>=0:${PORTSDIR}/devel/p5-DateTime-Format-Epoch
.endif

.if ${PORT_OPTIONS:MHATENABKMK}
BUILD_DEPENDS+=	p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite
.endif

.if ${PORT_OPTIONS:MPALMDOC}
BUILD_DEPENDS+=	p5-Palm-PalmDoc>=0:${PORTSDIR}/palm/p5-Palm-PalmDoc
.endif

.if ${PORT_OPTIONS:MPUBLISHSWF}
BUILD_DEPENDS+=	p5-SWF-Builder>=0:${PORTSDIR}/graphics/p5-SWF-Builder \
		libtext-wrapi18n-perl>=0:${PORTSDIR}/textproc/libtext-wrapi18n-perl
.endif

.if ${PORT_OPTIONS:MSUBSCRDBI}
BUILD_DEPENDS+=	p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class
.endif

.if ${PORT_OPTIONS:MFILTERPPT}
BUILD_DEPENDS+=	p5-URI-Find>=0:${PORTSDIR}/textproc/p5-URI-Find
.endif

.if ${PORT_OPTIONS:MKINOSEARCH}
BUILD_DEPENDS+=	p5-KinoSearch1>=0:${PORTSDIR}/textproc/p5-KinoSearch1
.endif

.if ${PORT_OPTIONS:MPUBLISHGMAIL}
BUILD_DEPENDS+=	p5-Net-SMTP-TLS>=0:${PORTSDIR}/mail/p5-Net-SMTP-TLS \
		p5-MIME-Lite>=0:${PORTSDIR}/mail/p5-MIME-Lite \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools
.endif

.if ${PORT_OPTIONS:MPUBDELICIOUS}
BUILD_DEPENDS+=	p5-Net-Delicious>=0:${PORTSDIR}/net/p5-Net-Delicious
.endif

.if ${PORT_OPTIONS:MESTRAIER}
BUILD_DEPENDS+=	p5-Search-Estraier>=0:${PORTSDIR}/textproc/p5-Search-Estraier
.endif

.if ${PORT_OPTIONS:MSRCHGREP}
BUILD_DEPENDS+=	p5-File-Grep>=0:${PORTSDIR}/devel/p5-File-Grep
.endif

.if ${PORT_OPTIONS:MPUBJSON}
BUILD_DEPENDS+=	p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck
.endif

.if ${PORT_OPTIONS:MFILSPAMASSN}
BUILD_DEPENDS+=	p5-Mail-SpamAssassin>=0:${PORTSDIR}/mail/p5-Mail-SpamAssassin
.endif

.if ${PORT_OPTIONS:MPROFANITY}
BUILD_DEPENDS+=	p5-Regexp-Common-profanity_us>=0:${PORTSDIR}/textproc/p5-Regexp-Common-profanity_us
.endif

.if ${PORT_OPTIONS:MHATENARSS}
BUILD_DEPENDS+=	p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize
.endif

.if ${PORT_OPTIONS:MSUBSCRFOAF}
BUILD_DEPENDS+=	p5-XML-FOAF>=0:${PORTSDIR}/textproc/p5-XML-FOAF
.endif

.if ${PORT_OPTIONS:MNOTIFYIRC}
BUILD_DEPENDS+=	p5-POE-Component-IRC>=0:${PORTSDIR}/irc/p5-POE-Component-IRC \
		p5-POE-Component-IKC>=0:${PORTSDIR}/devel/p5-POE-Component-IKC
.endif

.if ${PORT_OPTIONS:MHATENADIARY}
BUILD_DEPENDS+=	p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite
.endif

.if ${PORT_OPTIONS:MLIVEDOOR}
BUILD_DEPENDS+=	p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck
.endif

.if ${PORT_OPTIONS:MPINGSERVER}
BUILD_DEPENDS+=	p5-HTML-RSSAutodiscovery>=0:${PORTSDIR}/www/p5-HTML-RSSAutodiscovery
.endif

.if ${PORT_OPTIONS:MIMAGEINFO}
BUILD_DEPENDS+=	p5-Image-Info>=0:${PORTSDIR}/graphics/p5-Image-Info
.endif

.if ${PORT_OPTIONS:MFILMRKDWN}
BUILD_DEPENDS+=	p5-Text-Markdown>=0:${PORTSDIR}/textproc/p5-Text-Markdown
.endif

.if ${PORT_OPTIONS:MPUBLISHIMAP}
BUILD_DEPENDS+=	p5-Mail-IMAPClient>=0:${PORTSDIR}/mail/p5-Mail-IMAPClient
.endif

.if ${PORT_OPTIONS:MPUBLISHPDF}
BUILD_DEPENDS+=	p5-PDF-FromHTML>=0:${PORTSDIR}/textproc/p5-PDF-FromHTML
.endif

.if ${PORT_OPTIONS:MBLOGLINES}
BUILD_DEPENDS+=	p5-WebService-Bloglines>=0:${PORTSDIR}/www/p5-WebService-Bloglines
.endif

.if ${PORT_OPTIONS:MBABELFISH}
BUILD_DEPENDS+=	p5-WWW-Babelfish>=0:${PORTSDIR}/www/p5-WWW-Babelfish
.endif

.if ${PORT_OPTIONS:MCUSFEEDMIXI}
BUILD_DEPENDS+=	p5-WWW-Mixi>=0:${PORTSDIR}/www/p5-WWW-Mixi
.endif

.if ${PORT_OPTIONS:MCUSTOMSVNLOG}
BUILD_DEPENDS+=	p5-subversion>=0:${PORTSDIR}/devel/p5-subversion
.endif

.if ${PORT_OPTIONS:MNTFYNETSEND}
BUILD_DEPENDS+=	p5-Net-NetSend>=0:${PORTSDIR}/net-im/p5-Net-NetSend
.endif

.if ${PORT_OPTIONS:MFILHTMLSCRB}
BUILD_DEPENDS+=	p5-HTML-Scrubber>=0:${PORTSDIR}/www/p5-HTML-Scrubber
.endif

.if ${PORT_OPTIONS:MPLANETINI}
BUILD_DEPENDS+=	p5-Config-INI-Simple>=0:${PORTSDIR}/devel/p5-Config-INI-Simple
.endif

.if ${PORT_OPTIONS:MSUMMARYENG}
BUILD_DEPENDS+=	p5-Lingua-EN-Summarize>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Summarize
.endif

.if ${PORT_OPTIONS:MSUMJPN}
BUILD_DEPENDS+=	ja-p5-Lingua-JA-Summarize-Extract>=0:${PORTSDIR}/japanese/p5-Lingua-JA-Summarize-Extract
.endif

.if ${PORT_OPTIONS:MSUMTEXTORG}
BUILD_DEPENDS+=	p5-Text-Original>=0:${PORTSDIR}/textproc/p5-Text-Original
.endif

RUN_DEPENDS:=	${BUILD_DEPENDS}

post-patch:
	@${REINPLACE_CMD} -i '' '/auto_install/d' ${WRKSRC}/Makefile.PL
	@${RM} ${WRKSRC}/lib/Plagger/Plugin/Publish/Feed.pm.orig

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.yaml ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/assets
	(cd ${WRKSRC}/assets; ${TAR} cfz - . | ${TAR} zxf - -C ${STAGEDIR}${DATADIR}/assets)

.include <bsd.port.mk>
