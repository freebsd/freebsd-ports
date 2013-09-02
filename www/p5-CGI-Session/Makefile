# New ports collection makefile for:	p5-CGI-Session
# Date created:				12 June 2002
# Whom:					Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Session
PORTVERSION=	4.48
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKSTOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for persistent session management

USES=		perl5
USE_PERL5=	configure

MAN3=		\
		CGI::Session.3 \
		CGI::Session::Driver.3 \
		CGI::Session::Driver::DBI.3 \
		CGI::Session::Driver::db_file.3 \
		CGI::Session::Driver::file.3 \
		CGI::Session::Driver::mysql.3 \
		CGI::Session::Driver::postgresql.3 \
		CGI::Session::Driver::sqlite.3 \
		CGI::Session::ErrorHandler.3 \
		CGI::Session::ID::incr.3 \
		CGI::Session::ID::md5.3 \
		CGI::Session::ID::static.3 \
		CGI::Session::Serialize::default.3 \
		CGI::Session::Serialize::freezethaw.3 \
		CGI::Session::Serialize::storable.3 \
		CGI::Session::Test::Default.3 \
		CGI::Session::Tutorial.3 \

.include <bsd.port.mk>
