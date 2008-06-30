# New ports collection makefile for:	plagger
# Date created:				22 August 2006
# Whom:					sumikawa@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Plagger
PORTVERSION=	0.7.17
PORTREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	A pluggable RSS/Atom feed aggregator written in Perl

USE_PERL5=	yes

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/TimeZone.pm:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		${SITE_PERL}/DateTime/Locale.pm:${PORTSDIR}/devel/p5-DateTime-Locale \
		${SITE_PERL}/DateTime/Format/Mail.pm:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		${SITE_PERL}/DateTime/Format/Strptime.pm:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		${SITE_PERL}/DateTime/Format/W3CDTF.pm:${PORTSDIR}/devel/p5-DateTime-Format-W3CDTF \
		${SITE_PERL}/Cache.pm:${PORTSDIR}/devel/p5-Cache \
		${SITE_PERL}/Cache/Cache.pm:${PORTSDIR}/devel/p5-Cache-Cache \
		${SITE_PERL}/File/Find/Rule.pm:${PORTSDIR}/devel/p5-File-Find-Rule \
		${SITE_PERL}/File/HomeDir.pm:${PORTSDIR}/devel/p5-File-HomeDir \
		${SITE_PERL}/Module/Install.pm:${PORTSDIR}/devel/p5-Module-Install \
		${SITE_PERL}/Module/Pluggable/Fast.pm:${PORTSDIR}/devel/p5-Module-Pluggable-Fast \
		${SITE_PERL}/Term/Encoding.pm:${PORTSDIR}/devel/p5-Term-Encoding \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/MIME/Types.pm:${PORTSDIR}/mail/p5-MIME-Types \
		${SITE_PERL}/Text/Tags.pm:${PORTSDIR}/textproc/p5-Text-Tags \
		${SITE_PERL}/XML/Feed.pm:${PORTSDIR}/textproc/p5-XML-Feed \
		${SITE_PERL}/XML/RSS/LibXML.pm:${PORTSDIR}/textproc/p5-XML-RSS-LibXML \
		${SITE_PERL}/${PERL_ARCH}/Template/Toolkit.pod:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/Template/Provider/Encoding.pm:${PORTSDIR}/www/p5-Template-Provider-Encoding \
		${SITE_PERL}/HTML/ResolveLink.pm:${PORTSDIR}/www/p5-HTML-ResolveLink \
		${SITE_PERL}/URI/Fetch.pm:${PORTSDIR}/www/p5-URI-Fetch

OPTIONS=	BETTERENCODING "Better Encoding detection Support" on \
		PODTESTING "POD Testing Support" off \
		COOKIESHARING "Cookie sharing with Firefox Support" off \
		LIBERALXML "Liberal XML parsing Support" on \
		XPATH "XPath Support" on \
		BETTERHTML "Better html to text formatter" on \
		PUBLISHEXCEL "Publish::Excel Support" off \
		FILTERPIPE "Filter::Pipe Support" off \
		PUBLISHPLANET "Publish::Planet Support" on \
		PUBLISHCSV "Publish::CSV Support" off \
		FILDEGYT "Filter-DegradeYouTube" off \
		AUTHORNAME "Filter::ExtractAuthorName Support" off \
		GUESSLANG "Filter::GuessLanguage Support" off \
		GUESSTZ "Filter::GuessTimeZoneByDomain Support" off \
		HTMLTIDY "Filter::HTMLTidy Support" off \
		PUBLISHMT "Publish::MT Support" off \
		PUBSERLZR "Publish-Serializer Support" off \
		PUBICAL "Publish::iCal Support" off \
		ROMANIZE "Filter::Romanize Support" off \
		JAVASCRIPT "Publish::JavaScript Support" off \
		EMOTICON "Filter::Emoticon Support" off \
		FILHATENA "Filter::HatenaFormat Support" off \
		FILHATKTAG "Filter::HatenaKeywordTag" off \
		RULEFRESH "Rule::Fresh Support" on \
		SUBSCOPML "Subscription::OPML Support" on \
		FLICKRSEARCH "CustomFeed::FlickrSearch Support" off \
		HATENABKMK "Filter::HatenaBookmarkUsersCount Support" off \
		PALMDOC "Publish::PalmDoc Support" off \
		PUBLISHSWF "Publish::SWF Support" off \
		SUBSCRDBI "Subscription::DBI Support" off \
		NOTIFYBEEP "Notify::Beep Support" off \
		FILTERPPT "Filter::TTP Support" off \
		KINOSEARCH "Search::KinoSearch Support" off \
		PUBLISHGMAIL "Publish::Gmail Support" on \
		PUBDELICIOUS "Publish::Delicious Support" off \
		ESTRAIER "Search::Estraier Support" off \
		SRCHGREP "Search::Grep" off \
		PUBJSON "Publish::JSON Support" off \
		FILSPAMASSN "Filter-SpamAssassin Support" off \
		PROFANITY "Filter::Profanity Support" off \
		HATENARSS "Subscription::HatenaRSS Support" off \
		SUBSCRFOAF "Subscription::FOAF Support" off \
		NOTIFYIRC "Notify::IRC Support" off \
		AGRXANGO "Aggregator::Xango Support" off \
		HATENADIARY "Filter::HatenaDiaryKeywordLink Support" off \
		LIVEDOOR "Subscription::LivedoorReader Support" off \
		PINGSERVER "Subscription::PingServer Support" off \
		IMAGEINFO "Filter::ImageInfo Support" off \
		FILMRKDWN "Filter::Markdown Support" off \
		PUBLISHIMAP "Publish::IMAP Support" off \
		PUBLISHPDF "Publish::PDF Support" off \
		BLOGLINES "Subscription::Bloglines Support" on \
		BABELFISH "Filter::Babelfish Support" off \
		CUSFEEDMIXI "CustomFeed::Mixi Support" off \
		CUSTOMSVNLOG "CustomFeed::SVNLog Support" off \
		NTFYNETSEND "Notify::NetSend Support" off \
		FILHTMLSCRB "Filter::HTMLScrubber Support" on \
		PLANETINI "Subscription::PlanetINI Support" off \
		SUMMARYENG "Summary-English Support" off \
		SUMJPN "Summary::Japanes" off \
		SUMTEXTORG "Summary-TextOriginal Support" off \
# The below are not supported yet due to lack of depending ports
#		PRSJPNDATE "Parse Japanese datetime format" off \

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_BETTERENCODING)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Encode/Detect.pm:${PORTSDIR}/converters/p5-Encode-Detect
.endif

.if defined(WITH_PODTESTING)
BUILD_DEPENDS+=	${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage
.endif

.if defined(WITH_COOKIESHARING)
BUILD_DEPENDS+=	${SITE_PERL}/HTTP/Cookies/Mozilla.pm:${PORTSDIR}/www/p5-HTTP-Cookies-Mozilla
.endif

.if !defined(WITHOUT_LIBERALXML)
BUILD_DEPENDS+=	${SITE_PERL}/XML/Liberal.pm:${PORTSDIR}/textproc/p5-XML-Liberal  \
		${SITE_PERL}/XML/RSS/Liberal.pm:${PORTSDIR}/textproc/p5-XML-RSS-Liberal
.endif

.if !defined(WITHOUT_XPATH)
BUILD_DEPENDS+=	${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/HTML/FormatText.pm:${PORTSDIR}/textproc/p5-HTML-Format
.endif

.if !defined(WITHOUT_BETTERHTML)
BUILD_DEPENDS+=	${SITE_PERL}/HTML/TreeBuilder/XPath.pm:${PORTSDIR}/www/p5-HTML-TreeBuilder-XPath
.endif

#.if !defined(WITH_PRSJPNDATE)
#BUILD_DEPENDS+=	${SITE_PERL}/DateTime/Format/Japanese.pm:${PORTSDIR}/devel/p5-DateTime-Format-Japanese
#.endif

.if defined(WITH_PUBLISHEXCEL)
BUILD_DEPENDS+=	${SITE_PERL}/Spreadsheet/WriteExcel.pm:${PORTSDIR}/textproc/p5-Spreadsheet-WriteExcel
.endif

.if defined(WITH_FILTERPIPE)
BUILD_DEPENDS+=	${SITE_PERL}/IPC/Run.pm:${PORTSDIR}/devel/p5-IPC-Run
.endif

.if defined(WITH_PUBLISHPLANET)
BUILD_DEPENDS+=	${SITE_PERL}/File/Copy/Recursive.pm:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		${SITE_PERL}/HTML/Scrubber.pm:${PORTSDIR}/www/p5-HTML-Scrubber
.endif

.if defined(WITH_PUBLISHCSV)
BUILD_DEPENDS+=	${SITE_PERL}/Text/CSV_PP.pm:${PORTSDIR}/textproc/p5-Text-CSV_PP
.endif

.if defined(WITH_FILDEGYT)
BUILD_DEPENDS+=	${SITE_PERL}/WebService/YouTube.pm:${PORTSDIR}/www/p5-WebService-YouTube
.endif

.if defined(WITH_AUTHORNAME)
BUILD_DEPENDS+=	${SITE_PERL}/Email/Address.pm:${PORTSDIR}/mail/p5-Email-Address
.endif

.if defined(WITH_GUESSLANG)
BUILD_DEPENDS+=	${SITE_PERL}/Lingua/ZH/HanDetect.pm:${PORTSDIR}/chinese/p5-Lingua-ZH-HanDetect \
		${SITE_PERL}/Text/Language/Guess.pm:${PORTSDIR}/textproc/p5-Text-Language-Guess
.endif

.if defined(WITH_GUESSTZ)
BUILD_DEPENDS+=	${SITE_PERL}/IP/Country.pm:${PORTSDIR}/net/p5-IP-Country
.endif

.if defined(WITH_HTMLTIDY)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/HTML/Tidy.pm:${PORTSDIR}/textproc/p5-HTML-Tidy
.endif

.if defined(WITH_PUBLISHMT)
BUILD_DEPENDS+=	${SITE_PERL}/Net/MovableType.pm:${PORTSDIR}/net/p5-Net-MovableType
.endif

.if defined(WITH_PUBSERLZR)
BUILD_DEPENDS+=	${SITE_PERL}/Data/Serializer.pm:${PORTSDIR}/devel/p5-Data-Serializer
.endif

.if defined(WITH_PUBICAL)
BUILD_DEPENDS+=	${SITE_PERL}/Data/ICal.pm:${PORTSDIR}/deskutils/p5-Data-ICal \
		${SITE_PERL}/DateTime/Format/ICal.pm:${PORTSDIR}/devel/p5-DateTime-Format-ICal
.endif

.if defined(WITH_ROMANIZE)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Text/Kakasi.pm:${PORTSDIR}/japanese/p5-Text-Kakasi
.endif

.if defined(WITH_JAVASCRIPT)
BUILD_DEPENDS+=	${SITE_PERL}/Template/Plugin/JavaScript.pm:${PORTSDIR}/www/p5-Template-Plugin-JavaScript
.endif

.if defined(WITH_EMOTICON)
BUILD_DEPENDS+=	${SITE_PERL}/Text/Emoticon.pm:${PORTSDIR}/textproc/p5-Text-Emoticon
.endif

.if defined(WITH_FILHATENA)
BUILD_DEPENDS+=	${SITE_PERL}/Text/Hatena.pm:${PORTSDIR}/textproc/p5-Text-Hatena
.endif

.if defined(WITH_FILHATKTAG)
BUILD_DEPENDS+=	${SITE_PERL}/Hatena/Keyword.pm:${PORTSDIR}/textproc/p5-Hatena-Keyword
.endif

.if !defined(WITHOUT_RULEFRESH)
BUILD_DEPENDS+=	${SITE_PERL}/Time/Duration/Parse.pm:${PORTSDIR}/devel/p5-Time-Duration-Parse
.endif

.if !defined(WITHOUT_SUBSCOPML)
BUILD_DEPENDS+=	${SITE_PERL}/XML/OPML.pm:${PORTSDIR}/textproc/p5-XML-OPML
.endif

.if defined(WITH_FLICKRSEARCH)
BUILD_DEPENDS+=	${SITE_PERL}/Flickr/API.pm:${PORTSDIR}/www/p5-Flickr-API \
		${SITE_PERL}/DateTime/Format/Epoch.pm:${PORTSDIR}/devel/p5-DateTime-Format-Epoch
.endif

.if defined(WITH_HATENABKMK)
BUILD_DEPENDS+=	${SITE_PERL}/XMLRPC/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
.endif

.if defined(WITH_PALMDOC)
BUILD_DEPENDS+=	${SITE_PERL}/Palm/PalmDoc.pm:${PORTSDIR}/palm/p5-Palm-PalmDoc
.endif

.if defined(WITH_PUBLISHSWF)
BUILD_DEPENDS+=	${SITE_PERL}/SWF/Builder.pm:${PORTSDIR}/graphics/p5-SWF-Builder \
		${SITE_PERL}/Text/WrapI18N.pm:${PORTSDIR}/textproc/libtext-wrapi18n-perl
.endif

.if defined(WITH_SUBSCRDBI)
BUILD_DEPENDS+=	${SITE_PERL}/DBIx/Class/Schema.pm:${PORTSDIR}/databases/p5-DBIx-Class
.endif

.if defined(WITH_NOTIFYBEEP)
BUILD_DEPENDS+=	${SITE_PERL}/Audio/Beep.pm:${PORTSDIR}/audio/p5-Audio-Beep
.endif

.if defined(WITH_FILTERPPT)
BUILD_DEPENDS+=	${SITE_PERL}/URI/Find.pm:${PORTSDIR}/textproc/p5-URI-Find
.endif

.if defined(WITH_KINOSEARCH)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/KinoSearch.pm:${PORTSDIR}/textproc/p5-KinoSearch
.endif

.if !defined(WITHOUT_PUBLISHGMAIL)
BUILD_DEPENDS+=	${SITE_PERL}/Net/SMTP/TLS.pm:${PORTSDIR}/mail/p5-Net-SMTP-TLS \
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite \
		${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools
.endif

.if defined(WITH_PUBDELICIOUS)
BUILD_DEPENDS+=	${SITE_PERL}/Net/Delicious.pm:${PORTSDIR}/net/p5-Net-Delicious
.endif

.if defined(WITH_ESTRAIER)
BUILD_DEPENDS+=	${SITE_PERL}/Search/Estraier.pm:${PORTSDIR}/textproc/p5-Search-Estraier
.endif

.if defined(WITH_SRCHGREP)
BUILD_DEPENDS+=	${SITE_PERL}/File/Grep.pm:${PORTSDIR}/devel/p5-File-Grep
.endif

.if defined(WITH_PUBJSON)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/JSON/Syck.pm:${PORTSDIR}/textproc/p5-YAML-Syck
.endif

.if defined(WITH_FILSPAMASSN)
BUILD_DEPENDS+=	${SITE_PERL}/Mail/SpamAssassin.pm:${PORTSDIR}/mail/p5-Mail-SpamAssassin
.endif

.if defined(WITH_PROFANITY)
BUILD_DEPENDS+=	${SITE_PERL}/Regexp/Common/profanity_us.pm:${PORTSDIR}/textproc/p5-Regexp-Common-profanity_us
.endif

.if defined(WITH_HATENARSS)
BUILD_DEPENDS+=	${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize
.endif

.if defined(WITH_SUBSCRFOAF)
BUILD_DEPENDS+=	${SITE_PERL}/XML/FOAF.pm:${PORTSDIR}/textproc/p5-XML-FOAF
.endif

.if defined(WITH_NOTIFYIRC)
BUILD_DEPENDS+=	${SITE_PERL}/POE/Component/IRC.pm:${PORTSDIR}/irc/p5-POE-Component-IRC \
		${SITE_PERL}/POE/Component/IKC.pm:${PORTSDIR}/devel/p5-POE-Component-IKC
.endif

.if defined(WITH_AGRXANGO)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Cache/FastMmap.pm:${PORTSDIR}/devel/p5-Cache-FastMmap \
		${SITE_PERL}/POE/Component/Client/DNS.pm:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
		${SITE_PERL}/POE/Component/Client/HTTP.pm:${PORTSDIR}/www/p5-POE-Component-Client-HTTP \
		${SITE_PERL}/Xango.pm:${PORTSDIR}/www/p5-Xango \
		${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE
.endif

.if defined(WITH_HATENADIARY)
BUILD_DEPENDS+=	${SITE_PERL}/XMLRPC/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
.endif

.if defined(WITH_LIVEDOOR)
BUILD_DEPENDS+=	${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/${PERL_ARCH}/JSON/Syck.pm:${PORTSDIR}/textproc/p5-YAML-Syck
.endif

.if defined(WITH_PINGSERVER)
BUILD_DEPENDS+=	${SITE_PERL}/HTML/RSSAutodiscovery.pm:${PORTSDIR}/www/p5-HTML-RSSAutodiscovery
.endif

.if defined(WITH_IMAGEINFO)
BUILD_DEPENDS+=	${SITE_PERL}/Image/Info.pm:${PORTSDIR}/graphics/p5-Image-Info
.endif

.if defined(WITH_FILMRKDWN)
BUILD_DEPENDS+=	${SITE_PERL}/Text/Markdown.pm:${PORTSDIR}/textproc/p5-Text-Markdown
.endif

.if defined(WITH_PUBLISHIMAP)
BUILD_DEPENDS+=	${SITE_PERL}/Mail/IMAPClient.pm:${PORTSDIR}/mail/p5-Mail-IMAPClient
.endif

.if defined(WITH_PUBLISHPDF)
BUILD_DEPENDS+=	${SITE_PERL}/PDF/FromHTML.pm:${PORTSDIR}/textproc/p5-PDF-FromHTML
.endif

.if defined(WITH_BLOGLINES)
BUILD_DEPENDS+=	${SITE_PERL}/WebService/Bloglines.pm:${PORTSDIR}/www/p5-WebService-Bloglines
.endif

.if defined(WITH_BABELFISH)
BUILD_DEPENDS+=	${SITE_PERL}/WWW/Babelfish.pm:${PORTSDIR}/www/p5-WWW-Babelfish
.endif

.if defined(WITH_CUSFEEDMIXI)
BUILD_DEPENDS+=	${SITE_PERL}/WWW/Mixi.pm:${PORTSDIR}/www/p5-WWW-Mixi
.endif

.if defined(WITH_CUSTOMSVNLOG)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/SVN/Client.pm:${PORTSDIR}/devel/p5-subversion
.endif

.if defined(WITH_NTFYNETSEND)
BUILD_DEPENDS+=	${SITE_PERL}/Net/NetSend.pm:${PORTSDIR}/net-im/p5-Net-NetSend
.endif

.if defined(WITH_FILHTMLSCRB)
BUILD_DEPENDS+=	${SITE_PERL}/HTML/Scrubber.pm:${PORTSDIR}/www/p5-HTML-Scrubber
.endif

.if defined(WITH_PLANETINI)
BUILD_DEPENDS+=	${SITE_PERL}/Config/INI/Simple.pm:${PORTSDIR}/devel/p5-Config-INI-Simple
.endif

.if defined(WITH_SUMMARYENG)
BUILD_DEPENDS+=	${SITE_PERL}/Lingua/EN/Summarize.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Summarize
.endif

.if defined(WITH_SUMJPN)
BUILD_DEPENDS+=	${SITE_PERL}/Lingua/JA/Summarize/Extract.pm:${PORTSDIR}/japanese/p5-Lingua-JA-Summarize-Extract
.endif

.if defined(WITH_SUMTEXTORG)
BUILD_DEPENDS+=	${SITE_PERL}/Text/Original.pm:${PORTSDIR}/textproc/p5-Text-Original
.endif

RUN_DEPENDS=	${BUILD_DEPENDS}
PERL_CONFIGURE=	yes

MAN3=		Plagger.3 \
		Plagger::Cookies.3 \
		Plagger::Date.3 \
		Plagger::Plugin.3 \
		Plagger::Plugin::Aggregator::Null.3 \
		Plagger::Plugin::Aggregator::Simple.3 \
		Plagger::Plugin::Bundle::Defaults.3 \
		Plagger::Plugin::Bundle::Planet.3 \
		Plagger::Plugin::CustomFeed::2chSearch.3 \
		Plagger::Plugin::CustomFeed::AmazonAssociateReportJP.3 \
		Plagger::Plugin::CustomFeed::BloglinesCitations.3 \
		Plagger::Plugin::CustomFeed::Debug.3 \
		Plagger::Plugin::CustomFeed::FlickrSearch.3 \
		Plagger::Plugin::CustomFeed::Frepa.3 \
		Plagger::Plugin::CustomFeed::GoogleNews.3 \
		Plagger::Plugin::CustomFeed::Mailman.3 \
		Plagger::Plugin::CustomFeed::Mixi.3 \
		Plagger::Plugin::CustomFeed::MixiDiarySearch.3 \
		Plagger::Plugin::CustomFeed::POP3.3 \
		Plagger::Plugin::CustomFeed::PerlMonks.3 \
		Plagger::Plugin::CustomFeed::SVNLog.3 \
		Plagger::Plugin::CustomFeed::Script.3 \
		Plagger::Plugin::CustomFeed::Simple.3 \
		Plagger::Plugin::CustomFeed::YouTube.3 \
		Plagger::Plugin::CustomFeed::iTunesRecentPlay.3 \
		Plagger::Plugin::Filter::2chNewsokuTitle.3 \
		Plagger::Plugin::Filter::2chRSSContent.3 \
		Plagger::Plugin::Filter::AtomLinkRelated.3 \
		Plagger::Plugin::Filter::Babelfish.3 \
		Plagger::Plugin::Filter::Base.3 \
		Plagger::Plugin::Filter::BlogPet.3 \
		Plagger::Plugin::Filter::BloglinesContentNormalize.3 \
		Plagger::Plugin::Filter::BreakEntriesToFeeds.3 \
		Plagger::Plugin::Filter::BulkfeedsTerms.3 \
		Plagger::Plugin::Filter::CompositeFeed.3 \
		Plagger::Plugin::Filter::DegradeYouTube.3 \
		Plagger::Plugin::Filter::Delicious.3 \
		Plagger::Plugin::Filter::DeliciousFeedTags.3 \
		Plagger::Plugin::Filter::Emoticon.3 \
		Plagger::Plugin::Filter::EntryFullText.3 \
		Plagger::Plugin::Filter::ExtractAuthorName.3 \
		Plagger::Plugin::Filter::FeedBurnerPermalink.3 \
		Plagger::Plugin::Filter::FeedFlareStripper.3 \
		Plagger::Plugin::Filter::FetchEnclosure.3 \
		Plagger::Plugin::Filter::FetchEnclosure::Curl.3 \
		Plagger::Plugin::Filter::FetchEnclosure::ParallelUA.3 \
		Plagger::Plugin::Filter::FetchEnclosure::Wget.3 \
		Plagger::Plugin::Filter::FindEnclosures.3 \
		Plagger::Plugin::Filter::FloatingDateTime.3 \
		Plagger::Plugin::Filter::ForceTimeZone.3 \
		Plagger::Plugin::Filter::GuessLanguage.3 \
		Plagger::Plugin::Filter::GuessTimeZoneByDomain.3 \
		Plagger::Plugin::Filter::HEADEnclosureMetadata.3 \
		Plagger::Plugin::Filter::HTMLScrubber.3 \
		Plagger::Plugin::Filter::HTMLTidy.3 \
		Plagger::Plugin::Filter::HatenaBookmarkTag.3 \
		Plagger::Plugin::Filter::HatenaBookmarkUsersCount.3 \
		Plagger::Plugin::Filter::HatenaDiaryKeywordLink.3 \
		Plagger::Plugin::Filter::HatenaDiaryKeywordUnlink.3 \
		Plagger::Plugin::Filter::HatenaFormat.3 \
		Plagger::Plugin::Filter::HatenaKeywordTag.3 \
		Plagger::Plugin::Filter::ImageInfo.3 \
		Plagger::Plugin::Filter::Kansai.3 \
		Plagger::Plugin::Filter::LivedoorClipUsersCount.3 \
		Plagger::Plugin::Filter::LivedoorKeywordUnlink.3 \
		Plagger::Plugin::Filter::Markdown.3 \
		Plagger::Plugin::Filter::POPFile.3 \
		Plagger::Plugin::Filter::Pipe.3 \
		Plagger::Plugin::Filter::Profanity.3 \
		Plagger::Plugin::Filter::RSSLiberalDateTime.3 \
		Plagger::Plugin::Filter::RSSTimeZoneString.3 \
		Plagger::Plugin::Filter::Regexp.3 \
		Plagger::Plugin::Filter::ResolveRelativeLink.3 \
		Plagger::Plugin::Filter::RewriteEnclosureURL.3 \
		Plagger::Plugin::Filter::Rule.3 \
		Plagger::Plugin::Filter::SpamAssassin.3 \
		Plagger::Plugin::Filter::StripRSSAd.3 \
		Plagger::Plugin::Filter::StripTagsFromTitle.3 \
		Plagger::Plugin::Filter::TTP.3 \
		Plagger::Plugin::Filter::TagsToTitle.3 \
		Plagger::Plugin::Filter::Thumbnail.3 \
		Plagger::Plugin::Filter::TruePermalink.3 \
		Plagger::Plugin::Filter::UnicodeNormalize.3 \
		Plagger::Plugin::Filter::tDiaryComment.3 \
		Plagger::Plugin::Namespace::ApplePhotocast.3 \
		Plagger::Plugin::Namespace::HatenaFotolife.3 \
		Plagger::Plugin::Namespace::MediaRSS.3 \
		Plagger::Plugin::Notify::Audio.3 \
		Plagger::Plugin::Notify::Balloon.3 \
		Plagger::Plugin::Notify::Beep.3 \
		Plagger::Plugin::Notify::Campfire.3 \
		Plagger::Plugin::Notify::Command.3 \
		Plagger::Plugin::Notify::Eject.3 \
		Plagger::Plugin::Notify::Eject::darwin.3 \
		Plagger::Plugin::Notify::Eject::freebsd.3 \
		Plagger::Plugin::Notify::Eject::linux.3 \
		Plagger::Plugin::Notify::Eject::mswin32.3 \
		Plagger::Plugin::Notify::IRC.3 \
		Plagger::Plugin::Notify::MSAgent.3 \
		Plagger::Plugin::Notify::NetSend.3 \
		Plagger::Plugin::Notify::OpenBrowser.3 \
		Plagger::Plugin::Notify::OpenBrowser::FirefoxRemote.3 \
		Plagger::Plugin::Notify::SSTP.3 \
		Plagger::Plugin::Notify::Tiarra.3 \
		Plagger::Plugin::Notify::UpdatePing.3 \
		Plagger::Plugin::Publish::2chdat.3 \
		Plagger::Plugin::Publish::CSV.3 \
		Plagger::Plugin::Publish::Delicious.3 \
		Plagger::Plugin::Publish::Excel.3 \
		Plagger::Plugin::Publish::FOAFRoll.3 \
		Plagger::Plugin::Publish::Feed.3 \
		Plagger::Plugin::Publish::Gmail.3 \
		Plagger::Plugin::Publish::HatenaBookmark.3 \
		Plagger::Plugin::Publish::IMAP.3 \
		Plagger::Plugin::Publish::JSON.3 \
		Plagger::Plugin::Publish::JavaScript.3 \
		Plagger::Plugin::Publish::LivedoorClip.3 \
		Plagger::Plugin::Publish::MT.3 \
		Plagger::Plugin::Publish::MTWidget.3 \
		Plagger::Plugin::Publish::Maildir.3 \
		Plagger::Plugin::Publish::OPML.3 \
		Plagger::Plugin::Publish::OutlineText.3 \
		Plagger::Plugin::Publish::PDF.3 \
		Plagger::Plugin::Publish::PalmDoc.3 \
		Plagger::Plugin::Publish::Pipe.3 \
		Plagger::Plugin::Publish::Planet.3 \
		Plagger::Plugin::Publish::Playlog.3 \
		Plagger::Plugin::Publish::PowerPoint.3 \
		Plagger::Plugin::Publish::SWF.3 \
		Plagger::Plugin::Publish::Serializer.3 \
		Plagger::Plugin::Publish::Speech::MacOSX.3 \
		Plagger::Plugin::Publish::Takahashi.3 \
		Plagger::Plugin::Publish::iCal.3 \
		Plagger::Plugin::Search::Estraier.3 \
		Plagger::Plugin::Search::Grep.3 \
		Plagger::Plugin::Search::KinoSearch.3 \
		Plagger::Plugin::Search::Namazu.3 \
		Plagger::Plugin::Search::Rast.3 \
		Plagger::Plugin::Search::Spotlight.3 \
		Plagger::Plugin::Subscription::Bloglines.3 \
		Plagger::Plugin::Subscription::Bookmarks.3 \
		Plagger::Plugin::Subscription::Config.3 \
		Plagger::Plugin::Subscription::DBI.3 \
		Plagger::Plugin::Subscription::FOAF.3 \
		Plagger::Plugin::Subscription::Feed.3 \
		Plagger::Plugin::Subscription::File.3 \
		Plagger::Plugin::Subscription::HatenaGroup.3 \
		Plagger::Plugin::Subscription::HatenaRSS.3 \
		Plagger::Plugin::Subscription::LivedoorReader.3 \
		Plagger::Plugin::Subscription::OPML.3 \
		Plagger::Plugin::Subscription::Odeo.3 \
		Plagger::Plugin::Subscription::PingServer.3 \
		Plagger::Plugin::Subscription::Planet.3 \
		Plagger::Plugin::Subscription::PlanetINI.3 \
		Plagger::Plugin::Subscription::XOXO.3 \
		Plagger::Plugin::Subscription::XPath.3 \
		Plagger::Plugin::Summary::AppleScript.3 \
		Plagger::Plugin::Summary::Auto.3 \
		Plagger::Plugin::Summary::English.3 \
		Plagger::Plugin::Summary::GetSen.3 \
		Plagger::Plugin::Summary::HatenaBookmark.3 \
		Plagger::Plugin::Summary::Japanese.3 \
		Plagger::Plugin::Summary::Simple.3 \
		Plagger::Plugin::Summary::TextOriginal.3 \
		Plagger::Plugin::Summary::TrackbackRDF.3 \
		Plagger::Plugin::UserAgent::AuthenRequest.3 \
		Plagger::Plugin::UserAgent::RequestHeader.3 \
		Plagger::Plugin::Widget::BloglinesSubscription.3 \
		Plagger::Plugin::Widget::BulkfeedsSpamReport.3 \
		Plagger::Plugin::Widget::Delicious.3 \
		Plagger::Plugin::Widget::HatenaBookmarkUsersCount.3 \
		Plagger::Plugin::Widget::Simple.3 \
		Plagger::Rule::Deduped.3 \
		Plagger::Rule::Fresh.3 \
		Plagger::Rule::URLBL.3 \
		Plagger::Template.3

post-patch:
	${PERL} -pi -e '$$_ = "" if m|auto_install|' ${WRKSRC}/Makefile.PL
	${RM} ${WRKSRC}/lib/Plagger/Plugin/Publish/Feed.pm.orig

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.yaml ${EXAMPLESDIR}/
.endif
	@${MKDIR} ${DATADIR}/assets
	(cd ${WRKSRC}/assets; ${TAR} cfz - . | ${TAR} zxf - -C ${DATADIR}/assets)

.include <bsd.port.post.mk>
