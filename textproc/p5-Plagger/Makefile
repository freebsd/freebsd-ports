# Created by: sumikawa@FreeBSD.org
# $FreeBSD$

PORTNAME=	Plagger
PORTVERSION=	0.7.17
PORTREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pluggable RSS/Atom feed aggregator written in Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-TimeZone>=0:devel/p5-DateTime-TimeZone \
		p5-DateTime-Locale>=0:devel/p5-DateTime-Locale \
		p5-DateTime-Format-Mail>=0:devel/p5-DateTime-Format-Mail \
		p5-DateTime-Format-Strptime>=0:devel/p5-DateTime-Format-Strptime \
		p5-DateTime-Format-W3CDTF>=0:devel/p5-DateTime-Format-W3CDTF \
		p5-Cache>=0:devel/p5-Cache \
		p5-Cache-Cache>=0:devel/p5-Cache-Cache \
		p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-Module-Install>=0:devel/p5-Module-Install \
		p5-Module-Pluggable-Fast>=0:devel/p5-Module-Pluggable-Fast \
		p5-Term-Encoding>=0:devel/p5-Term-Encoding \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-MIME-Types>=0:mail/p5-MIME-Types \
		p5-Text-Tags>=0:textproc/p5-Text-Tags \
		p5-XML-Feed>=0:textproc/p5-XML-Feed \
		p5-XML-RSS-LibXML>=0:textproc/p5-XML-RSS-LibXML \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Template-Provider-Encoding>=0:www/p5-Template-Provider-Encoding \
		p5-HTML-ResolveLink>=0:www/p5-HTML-ResolveLink \
		p5-URI-Fetch>=0:www/p5-URI-Fetch \
		p5-YAML>=0:textproc/p5-YAML

NO_ARCH=	yes
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
		NOTIFYIRC NTFYNETSEND PINGSERVER PLANETINI PODTESTING \
		PROFANITY PRSJPNDATE PRSJPNDATE PUBDELICIOUS PUBICAL PUBJSON \
		PUBLISHCSV PUBLISHEXCEL PUBLISHGMAIL PUBLISHIMAP PUBLISHMT \
		PUBLISHPDF PUBLISHPLANET PUBLISHSWF PUBSERLZR ROMANIZE \
		RULEFRESH SRCHGREP SUBSCOPML SUBSCRDBI SUBSCRFOAF SUMJPN \
		SUMMARYENG SUMTEXTORG XPATH \
		DOCS EXAMPLES

AUTHORNAME_DESC=	Filter::ExtractAuthorName Support
BABELFISH_DESC=		Filter::Babelfish Support
BETTERENCODING_DESC=	Better Encoding detection Support
BETTERHTML_DESC=	Better html to text formatter
BLOGLINES_DESC=		Subscription::Bloglines Support
COOKIESHARING_DESC=	Cookie sharing with Firefox Support
CUSFEEDMIXI_DESC=	CustomFeed::Mixi Support
CUSTOMSVNLOG_DESC=	CustomFeed::SVNLog Support
EMOTICON_DESC=		Filter::Emoticon Support
ESTRAIER_DESC=		Search::Estraier Support
FILDEGYT_DESC=		Filter-DegradeYouTube
FILHATENA_DESC=		Filter::HatenaFormat Support
FILHATKTAG_DESC=	Filter::HatenaKeywordTag
FILHTMLSCRB_DESC=	Filter::HTMLScrubber Support
FILMRKDWN_DESC=		Filter::Markdown Support
FILSPAMASSN_DESC=	Filter-SpamAssassin Support
FILTERPIPE_DESC=	Filter::Pipe Support
FILTERPPT_DESC=		Filter::TTP Support
FLICKRSEARCH_DESC=	CustomFeed::FlickrSearch Support
GUESSLANG_DESC=		Filter::GuessLanguage Support
GUESSTZ_DESC=		Filter::GuessTimeZoneByDomain Support
HATENABKMK_DESC=	Filter::HatenaBookmarkUsersCount Support
HATENADIARY_DESC=	Filter::HatenaDiaryKeywordLink Support
HATENARSS_DESC=		Subscription::HatenaRSS Support
HTMLTIDY_DESC=		Filter::HTMLTidy Support
IMAGEINFO_DESC=		Filter::ImageInfo Support
JAVASCRIPT_DESC=	Publish::JavaScript Support
KINOSEARCH_DESC=	Search::KinoSearch Support
LIBERALXML_DESC=	Liberal XML parsing Support
LIVEDOOR_DESC=		Subscription::LivedoorReader Support
NOTIFYIRC_DESC=		Notify::IRC Support
NTFYNETSEND_DESC=	Notify::NetSend Support
PINGSERVER_DESC=	Subscription::PingServer Support
PLANETINI_DESC=		Subscription::PlanetINI Support
PODTESTING_DESC=	Testing Support
PROFANITY_DESC=		Filter::Profanity Support
PRSJPNDATE_DESC=	Parse Japanese datetime format
PUBDELICIOUS_DESC=	Publish::Delicious Support
PUBICAL_DESC=		Publish::iCal Support
PUBJSON_DESC=		Publish::JSON Support
PUBLISHCSV_DESC=	Publish::CSV Support
PUBLISHEXCEL_DESC=	Publish::Excel Support
PUBLISHGMAIL_DESC=	Publish::Gmail Support
PUBLISHIMAP_DESC=	Publish::IMAP Support
PUBLISHMT_DESC=		Publish::MT Support
PUBLISHPDF_DESC=	Publish::PDF Support
PUBLISHPLANET_DESC=	Publish::Planet Support
PUBLISHSWF_DESC=	Publish::SWF Support
PUBSERLZR_DESC=		Publish-Serializer Support
ROMANIZE_DESC=		Filter::Romanize Support
RULEFRESH_DESC=		Rule::Fresh Support
SRCHGREP_DESC=		Search::Grep
SUBSCOPML_DESC=		Subscription::OPML Support
SUBSCRDBI_DESC=		Subscription::DBI Support
SUBSCRFOAF_DESC=	Subscription::FOAF Support
SUMJPN_DESC=		Summary::Japanes
SUMMARYENG_DESC=	Summary-English Support
SUMTEXTORG_DESC=	Summary-TextOriginal Support
XPATH_DESC=		XPath Support

OPTIONS_DEFAULT=	BETTERENCODING LIBERALXML XPATH BETTERHTML \
			PUBLISHPLANET GUESSTZ EMOTICON RULEFRESH SUBSCOPML \
			SUBSCRDBI PUBLISHGMAIL HATENARSS SUBSCRFOAF LIVEDOOR \
			PINGSERVER BLOGLINES FILHTMLSCRB PLANETINI

AUTHORNAME_RUN_DEPENDS= \
		p5-Email-Address>=0:mail/p5-Email-Address

BABELFISH_RUN_DEPENDS= \
		p5-WWW-Babelfish>=0:www/p5-WWW-Babelfish

BETTERENCODING_RUN_DEPENDS= \
		p5-Encode-Detect>=0:converters/p5-Encode-Detect

BETTERHTML_RUN_DEPENDS= \
		p5-HTML-TreeBuilder-XPath>=0:www/p5-HTML-TreeBuilder-XPath

BLOGLINES_RUN_DEPENDS= \
		p5-WebService-Bloglines>=0:www/p5-WebService-Bloglines

COOKIESHARING_RUN_DEPENDS= \
		p5-HTTP-Cookies-Mozilla>=0:www/p5-HTTP-Cookies-Mozilla

CUSFEEDMIXI_RUN_DEPENDS= \
		p5-WWW-Mixi>=0:www/p5-WWW-Mixi

CUSTOMSVNLOG_RUN_DEPENDS= \
		p5-subversion>=0:devel/p5-subversion

EMOTICON_RUN_DEPENDS= \
		p5-Text-Emoticon>=0:textproc/p5-Text-Emoticon

ESTRAIER_RUN_DEPENDS= \
		p5-Search-Estraier>=0:textproc/p5-Search-Estraier

FILDEGYT_RUN_DEPENDS= \
		p5-WebService-YouTube>=0:www/p5-WebService-YouTube

FILHATENA_RUN_DEPENDS= \
		p5-Text-Hatena>=0:textproc/p5-Text-Hatena

FILHATKTAG_RUN_DEPENDS= \
		p5-Hatena-Keyword>=0:textproc/p5-Hatena-Keyword

FILHTMLSCRB_RUN_DEPENDS= \
		p5-HTML-Scrubber>=0:www/p5-HTML-Scrubber

FILMRKDWN_RUN_DEPENDS= \
		p5-Text-Markdown>=0:textproc/p5-Text-Markdown

FILSPAMASSN_RUN_DEPENDS= \
		spamassassin>=0:mail/spamassassin

FILTERPIPE_RUN_DEPENDS= \
		p5-IPC-Run>=0:devel/p5-IPC-Run

FILTERPPT_RUN_DEPENDS= \
		p5-URI-Find>=0:textproc/p5-URI-Find

FLICKRSEARCH_RUN_DEPENDS= \
		p5-Flickr-API>=0:www/p5-Flickr-API \
		p5-DateTime-Format-Epoch>=0:devel/p5-DateTime-Format-Epoch

GUESSLANG_RUN_DEPENDS= \
		p5-Lingua-ZH-HanDetect>=0:chinese/p5-Lingua-ZH-HanDetect \
		p5-Text-Language-Guess>=0:textproc/p5-Text-Language-Guess

GUESSTZ_RUN_DEPENDS= \
		p5-IP-Country>=0:net/p5-IP-Country

HATENABKMK_RUN_DEPENDS= \
		p5-SOAP-Lite>=0:net/p5-SOAP-Lite

HATENADIARY_RUN_DEPENDS= \
		p5-SOAP-Lite>=0:net/p5-SOAP-Lite

HATENARSS_RUN_DEPENDS= \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize

HTMLTIDY_RUN_DEPENDS= \
		p5-HTML-Tidy>=0:textproc/p5-HTML-Tidy

IMAGEINFO_RUN_DEPENDS= \
		p5-Image-Info>=0:graphics/p5-Image-Info

JAVASCRIPT_RUN_DEPENDS= \
		p5-Template-Plugin-JavaScript>=0:www/p5-Template-Plugin-JavaScript

KINOSEARCH_RUN_DEPENDS= \
		p5-KinoSearch1>=0:textproc/p5-KinoSearch1

LIBERALXML_RUN_DEPENDS= \
		p5-XML-Liberal>=0:textproc/p5-XML-Liberal  \
		p5-XML-RSS-Liberal>=0:textproc/p5-XML-RSS-Liberal

LIVEDOOR_RUN_DEPENDS= \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck

NOTIFYIRC_RUN_DEPENDS= \
		p5-POE-Component-IRC>=0:irc/p5-POE-Component-IRC \
		p5-POE-Component-IKC>=0:devel/p5-POE-Component-IKC

NTFYNETSEND_RUN_DEPENDS= \
		p5-Net-NetSend>=0:net-im/p5-Net-NetSend

PINGSERVER_RUN_DEPENDS= \
		p5-HTML-RSSAutodiscovery>=0:www/p5-HTML-RSSAutodiscovery

PLANETINI_RUN_DEPENDS= \
		p5-Config-INI-Simple>=0:devel/p5-Config-INI-Simple

PODTESTING_RUN_DEPENDS= \
		p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage

PROFANITY_RUN_DEPENDS= \
		p5-Regexp-Common-profanity_us>=0:textproc/p5-Regexp-Common-profanity_us

PRSJPNDATE_RUN_DEPENDS= \
		ja-p5-DateTime-Format-Japanese>=0:japanese/p5-DateTime-Format-Japanese

PUBDELICIOUS_RUN_DEPENDS= \
		p5-Net-Delicious>=0:net/p5-Net-Delicious

PUBICAL_RUN_DEPENDS= \
		p5-Data-ICal>=0:deskutils/p5-Data-ICal \
		p5-DateTime-Format-ICal>=0:devel/p5-DateTime-Format-ICal

PUBJSON_RUN_DEPENDS= \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck

PUBLISHCSV_RUN_DEPENDS= \
		p5-Text-CSV>=0:textproc/p5-Text-CSV

PUBLISHEXCEL_RUN_DEPENDS= \
		p5-Spreadsheet-WriteExcel>=0:textproc/p5-Spreadsheet-WriteExcel

PUBLISHGMAIL_RUN_DEPENDS= \
		p5-Net-SMTP-TLS>=0:mail/p5-Net-SMTP-TLS \
		p5-MIME-Lite>=0:mail/p5-MIME-Lite \
		p5-Mail-Tools>=0:mail/p5-Mail-Tools

PUBLISHIMAP_RUN_DEPENDS= \
		p5-Mail-IMAPClient>=0:mail/p5-Mail-IMAPClient

PUBLISHMT_RUN_DEPENDS= \
		p5-Net-MovableType>=0:net/p5-Net-MovableType

PUBLISHPDF_RUN_DEPENDS= \
		p5-PDF-FromHTML>=0:textproc/p5-PDF-FromHTML

PUBLISHPLANET_RUN_DEPENDS= \
		p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-HTML-Scrubber>=0:www/p5-HTML-Scrubber

PUBLISHSWF_RUN_DEPENDS= \
		p5-SWF-Builder>=0:graphics/p5-SWF-Builder \
		p5-Text-WrapI18N>=0:textproc/p5-Text-WrapI18N

PUBSERLZR_RUN_DEPENDS= \
		p5-Data-Serializer>=0:devel/p5-Data-Serializer

ROMANIZE_RUN_DEPENDS= \
		ja-p5-Text-Kakasi>=0:japanese/p5-Text-Kakasi

RULEFRESH_RUN_DEPENDS= \
		p5-Time-Duration-Parse>=0:devel/p5-Time-Duration-Parse

SRCHGREP_RUN_DEPENDS= \
		p5-File-Grep>=0:devel/p5-File-Grep

SUBSCOPML_RUN_DEPENDS= \
		p5-XML-OPML>=0:textproc/p5-XML-OPML

SUBSCRDBI_RUN_DEPENDS= \
		p5-DBIx-Class>=0:databases/p5-DBIx-Class

SUBSCRFOAF_RUN_DEPENDS= \
		p5-XML-FOAF>=0:textproc/p5-XML-FOAF

SUMJPN_RUN_DEPENDS= \
		ja-p5-Lingua-JA-Summarize-Extract>=0:japanese/p5-Lingua-JA-Summarize-Extract

SUMMARYENG_RUN_DEPENDS= \
		p5-Lingua-EN-Summarize>=0:textproc/p5-Lingua-EN-Summarize

SUMTEXTORG_RUN_DEPENDS= \
		p5-Text-Original>=0:textproc/p5-Text-Original

XPATH_RUN_DEPENDS= \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-HTML-Format>=0:textproc/p5-HTML-Format

post-patch:
	@${REINPLACE_CMD} -i '' '/auto_install/d' ${WRKSRC}/Makefile.PL
	@${RM} ${WRKSRC}/lib/Plagger/Plugin/Publish/Feed.pm.orig

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.yaml ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/assets
	(cd ${WRKSRC}/assets; ${TAR} cfz - . | ${TAR} zxf - -C ${STAGEDIR}${DATADIR}/assets)

.include <bsd.port.mk>
