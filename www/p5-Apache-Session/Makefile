# New ports collection makefile for:	p5-Apache-Session
# Date created:				March 13, 2000
# Whom:					Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	Apache-Session
PORTVERSION=	1.87
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A persistence framework for session data

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes

MAN3=		Apache::Session.3 \
		Apache::Session::DB_File.3 \
		Apache::Session::File.3 \
		Apache::Session::Flex.3 \
		Apache::Session::Generate::MD5.3 \
		Apache::Session::Generate::ModUniqueId.3 \
		Apache::Session::Generate::ModUsertrack.3 \
		Apache::Session::Informix.3 \
		Apache::Session::Lock::File.3 \
		Apache::Session::Lock::MySQL.3 \
		Apache::Session::Lock::Null.3 \
		Apache::Session::Lock::Semaphore.3 \
		Apache::Session::Lock::Sybase.3 \
		Apache::Session::MySQL.3 \
		Apache::Session::Oracle.3 \
		Apache::Session::Postgres.3 \
		Apache::Session::Serialize::Base64.3 \
		Apache::Session::Serialize::Storable.3 \
		Apache::Session::Serialize::Sybase.3 \
		Apache::Session::Serialize::UUEncode.3 \
		Apache::Session::Store::DB_File.3 \
		Apache::Session::Store::File.3 \
		Apache::Session::Store::Informix.3 \
		Apache::Session::Store::MySQL.3 \
		Apache::Session::Store::Oracle.3 \
		Apache::Session::Store::Postgres.3 \
		Apache::Session::Store::Sybase.3 \
		Apache::Session::Sybase.3

.include <bsd.port.mk>
