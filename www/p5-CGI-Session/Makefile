# New ports collection makefile for:	p5-CGI-Session
# Date created:				12 June 2002
# Whom:					Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Session
PORTVERSION=	3.95
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Perl extension for persistent session management

PERL_CONFIGURE=	yes

MAN3=		CGI::Session::DB_File.3 \
		CGI::Session::Example.3 \
		CGI::Session::MySQL.3 \
		CGI::Session::File.3 \
		CGI::Session.3 \
		CGI::Session::ID::Incr.3 \
		CGI::Session::ID::SHA1.3 \
		CGI::Session::Serialize::FreezeThaw.3 \
		CGI::Session::Serialize::Default.3 \
		CGI::Session::BluePrint.3 \
		CGI::Session::ID::MD5.3 \
		CGI::Session::PostgreSQL.3 \
		CGI::Session::Tutorial.3 \
		CGI::Session::CookBook.3 \
		CGI::Session::Serialize::Storable.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
