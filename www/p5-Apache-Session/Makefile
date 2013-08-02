# Created by: Frank Mayhar <frank@exit.com>
# $FreeBSD$

PORTNAME=	Apache-Session
PORTVERSION=	1.90
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Persistence framework for session data

BUILD_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS+=	p5-Test-Deep>=0.082:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Exception>=0.15:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Database>=0:${PORTSDIR}/databases/p5-Test-Database

USES=		perl5
USE_PERL5=	modbuild

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
		Apache::Session::MySQL::NoLock.3 \
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
