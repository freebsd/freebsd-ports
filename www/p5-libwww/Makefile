# New ports collection makefile for:	p5-libwww
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libwww
PORTVERSION=	5.832
CATEGORIES=	www perl5 devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	LWP
PKGNAMEPREFIX=	p5-
DISTNAME=	libwww-perl-${PORTVERSION}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Perl5 library for WWW access

RUN_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	--aliases

MAN1=	GET.1 HEAD.1 POST.1 lwp-download.1 lwp-mirror.1 \
	lwp-request.1 lwp-rget.1 lwp-dump.1

MAN3=	Bundle::LWP.3 File::Listing.3 HTML::Form.3 HTTP::Config.3 \
	HTTP::Cookies.3 \
	HTTP::Cookies::Microsoft.3 HTTP::Cookies::Netscape.3 \
	HTTP::Daemon.3 HTTP::Date.3 HTTP::Headers.3 \
	HTTP::Headers::Util.3 HTTP::Message.3 HTTP::Negotiate.3 \
	HTTP::Request.3 HTTP::Request::Common.3 HTTP::Response.3 \
	HTTP::Status.3 LWP.3 LWP::Authen::Ntlm.3 LWP::ConnCache.3 \
	LWP::Debug.3 LWP::MediaTypes.3 \
	LWP::MemberMixin.3 LWP::Protocol.3 LWP::RobotUA.3 LWP::Simple.3 \
	LWP::UserAgent.3 Net::HTTP.3 Net::HTTP::NB.3 WWW::RobotRules.3 \
	WWW::RobotRules::AnyDBM_File.3 lwpcook.3 lwptut.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-Compress-Zlib>=1.10:${PORTSDIR}/archivers/p5-Compress-Zlib
.endif
.include <bsd.port.post.mk>
