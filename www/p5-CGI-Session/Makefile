# New ports collection makefile for:	p5-CGI-Session
# Date created:				12 June 2002
# Whom:					Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Session
PORTVERSION=	4.34
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MA/MARKSTOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Perl extension for persistent session management

PERL_CONFIGURE=	yes

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
