# New ports collection makefile for:	p5-libwww
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	p5-libwww
PORTVERSION=	5.52
PORTREVISION=	2
CATEGORIES=	www perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	LWP
DISTNAME=	libwww-perl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MD5.pm:${PORTSDIR}/security/p5-MD5 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI.pm:${PORTSDIR}/net/p5-URI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		lwp-download.1 \
		lwp-mirror.1 \
		lwp-request.1 \
		lwp-rget.1
MAN3=		Bundle::LWP.3 \
		File::Listing.3 \
		HTML::Form.3 \
		HTTP::Cookies.3 \
		HTTP::Daemon.3 \
		HTTP::Date.3 \
		HTTP::Headers.3 \
		HTTP::Headers::Util.3 \
		HTTP::Message.3 \
		HTTP::Negotiate.3 \
		HTTP::Request.3 \
		HTTP::Request::Common.3 \
		HTTP::Response.3 \
		HTTP::Status.3 \
		LWP.3 \
		LWP::Debug.3 \
		LWP::MediaTypes.3 \
		LWP::MemberMixin.3 \
		LWP::Protocol.3 \
		LWP::RobotUA.3 \
		LWP::Simple.3 \
		LWP::UserAgent.3 \
		WWW::RobotRules.3 \
		WWW::RobotRules::AnyDBM_File.3 \
		lwpcook.3

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
