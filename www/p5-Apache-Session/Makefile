# New ports collection makefile for:	p5-Apache-Session
# Date created:				March 13, 2000
# Whom:					Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	Apache-Session
PORTVERSION=	1.54
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	frank@exit.com

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::Session.3 \
		Apache::Session::DB_File.3 \
		Apache::Session::File.3 \
		Apache::Session::Flex.3 \
		Apache::Session::Generate::MD5.3 \
		Apache::Session::Generate::ModUniqueId.3 \
		Apache::Session::Generate::ModUsertrack.3 \
		Apache::Session::Lock::File.3 \
		Apache::Session::Lock::MySQL.3 \
		Apache::Session::Lock::Null.3 \
		Apache::Session::Lock::Semaphore.3 \
		Apache::Session::MySQL.3 \
		Apache::Session::Oracle.3 \
		Apache::Session::Postgres.3 \
		Apache::Session::Serialize::Base64.3 \
		Apache::Session::Serialize::Storable.3 \
		Apache::Session::Serialize::Sybase.3 \
		Apache::Session::Serialize::UUEncode.3 \
		Apache::Session::Store::DB_File.3 \
		Apache::Session::Store::File.3 \
		Apache::Session::Store::MySQL.3 \
		Apache::Session::Store::Oracle.3 \
		Apache::Session::Store::Postgres.3 \
		Apache::Session::Store::Sybase.3 \
		Apache::Session::Sybase.3

.include <bsd.port.mk>
