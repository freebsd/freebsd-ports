# New ports collection makefile for:	p5-libwww
# http://www.sn.no/libwww-perl/
# Version required:                     5.18
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.13 1997/11/22 13:01:37 ache Exp $
#

DISTNAME=       libwww-perl-5.18
PKGNAME=        p5-libwww-5.18
CATEGORIES=     www perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	URI

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	${PREFIX}/lib/perl5/site_perl/MD5.pm:${PORTSDIR}/security/p5-MD5 \
		${PREFIX}/lib/perl5/site_perl/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${PREFIX}/lib/perl5/site_perl/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

USE_PERL5=	YES

MAN1=           lwp-download.1 \
		lwp-mirror.1 \
		lwp-request.1 \
		lwp-rget.1
MAN3=           File::CounterFile.3 \
		HTML::FormatPS.3 \
		HTTP::Request::Common.3 \
		HTML::Parser.3 \
		HTML::FormatText.3 \
		LWP::SecureSocket.3 \
		LWP::Protocol.3 \
		HTML::AsSubs.3 \
		HTTP::Headers::Util.3 \
		HTTP::Request.3 \
		LWP::IO.3 \
		LWP::RobotUA.3 \
		HTTP::Response.3 \
		HTML::HeadParser.3 \
		HTTP::Daemon.3 \
		HTML::LinkExtor.3 \
		WWW::RobotRules.3 \
		URI::URL.3 \
		File::Listing.3 \
		LWP::Debug.3 \
		HTML::Filter.3 \
		URI::Heuristic.3 \
		HTTP::Negotiate.3 \
		URI::Escape.3 \
		LWP::UserAgent.3 \
		HTTP::Status.3 \
		LWP.3 \
		HTTP::Message.3 \
		LWP::MediaTypes.3 \
		HTML::Formatter.3 \
		LWP::TkIO.3 \
		Font::AFM.3 \
		HTML::TreeBuilder.3 \
		HTTP::Cookies.3 \
		Bundle::LWP.3 \
		LWP::MemberMixin.3 \
		lwpcook.3 \
		HTML::Parse.3 \
		LWP::Socket.3 \
		HTML::Entities.3 \
		HTTP::Headers.3 \
		LWP::Simple.3 \
		HTTP::Date.3 \
		WWW::RobotRules::AnyDBM_File.3 \
		HTML::Element.3

MAN3PREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
