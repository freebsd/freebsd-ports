# New ports collection makefile for:	p5-libwww
# http://www.linpro.no/lwp/
# Version required:                     5.36
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.28 1998/11/15 15:36:06 ache Exp $
#

DISTNAME=       libwww-perl-5.36
PKGNAME=        p5-libwww-5.36
CATEGORIES=     www perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=     LWP

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/i386-freebsd/MD5.pm:${PORTSDIR}/security/p5-MD5 \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/i386-freebsd/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/i386-freebsd/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser

USE_PERL5=	YES

MAN1=           lwp-download.1 \
		lwp-mirror.1 \
		lwp-request.1 \
		lwp-rget.1
MAN3=           Bundle::LWP.3 \
		File::Listing.3 \
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
		URI::Escape.3 \
		URI::Heuristic.3 \
		URI::URL.3 \
		WWW::RobotRules.3 \
		WWW::RobotRules::AnyDBM_File.3 \
		lwpcook.3

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${PERL} Makefile.PL PREFIX=${PREFIX} \
				     INSTALLMAN1DIR=${PREFIX}/man/man1 \
				     INSTALLSCRIPT=${PREFIX}/bin

.include <bsd.port.mk>
