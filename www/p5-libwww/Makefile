# New ports collection makefile for:	p5-libwww
# Version required:			5.03
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id$
#

DISTNAME=	libwww-perl-5.03
PKGNAME=	p5-libwww-5.03
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/URI/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/URI/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/URI/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/URI/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/URI/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/URI/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5 \
		${PREFIX}/lib/perl5/site_perl/MD5.pm:${PORTSDIR}/security/p5-MD5 \
		${PREFIX}/lib/perl5/site_perl/Net/FTP.pm:${PORTSDIR}/net/p5-Net

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in File::CounterFile File::Listing Font::AFM HTML::AsSubs HTML::Element HTML::Entities HTML::FormatPS HTML::FormatText HTML::Formatter HTML::HeadParser HTML::LinkExtor HTML::Parse HTML::Parser HTML::TreeBuilder HTTP::Date HTTP::Headers HTTP::Message HTTP::Negotiate HTTP::Request HTTP::Response HTTP::Status LWP LWP::Debug LWP::IO LWP::MediaTypes LWP::MemberMixin LWP::Protocol LWP::RobotUA LWP::Simple LWP::Socket LWP::TkIO LWP::UserAgent MIME::Base64 MIME::QuotedPrint URI::Escape URI::URL WWW::RobotRules WWW::RobotRules::AnyDBM_File lwpcook; do \
			gzip -9nf ${PREFIX}/lib/perl5/man/man3/$$file.3; \
		done
		@ for file in lwp-mirror lwp-request lwp-rget; do \
			gzip -9nf ${PREFIX}/man/man1/$$file.1; \
		done
.endif

.include <bsd.port.mk>
