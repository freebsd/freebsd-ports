# New ports collection makefile for:	p5-libwww
# Version required:			5.03
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.3 1996/11/18 08:47:28 asami Exp $
#

DISTNAME=	libwww-perl-5.03
PKGNAME=	p5-libwww-5.03
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	URI

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5 \
		${PREFIX}/lib/perl5/site_perl/MD5.pm:${PORTSDIR}/security/p5-MD5 \
		${PREFIX}/lib/perl5/site_perl/Net/FTP.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

MAN1=		lwp-mirror.1 lwp-request.1 lwp-rget.1
MAN3=		File::CounterFile.3 File::Listing.3 Font::AFM.3 \
		HTML::AsSubs.3 HTML::Element.3 HTML::Entities.3 \
		HTML::FormatPS.3 HTML::FormatText.3 HTML::Formatter.3 \
		HTML::HeadParser.3 HTML::LinkExtor.3 HTML::Parse.3 \
		HTML::Parser.3 HTML::TreeBuilder.3 HTTP::Date.3 \
		HTTP::Headers.3 HTTP::Message.3 HTTP::Negotiate.3 \
		HTTP::Request.3 HTTP::Response.3 HTTP::Status.3 LWP.3 \
		LWP::Debug.3 LWP::IO.3 LWP::MediaTypes.3 \
		LWP::MemberMixin.3 LWP::Protocol.3 LWP::RobotUA.3 \
		LWP::Simple.3 LWP::Socket.3 LWP::TkIO.3 LWP::UserAgent.3 \
		MIME::Base64.3 MIME::QuotedPrint.3 URI::Escape.3 \
		URI::URL.3 WWW::RobotRules.3 \
		WWW::RobotRules::AnyDBM_File.3 lwpcook.3
MAN3PREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
