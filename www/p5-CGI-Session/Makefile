# New ports collection makefile for:	p5-CGI-Session
# Date created:				12 June 2002
# Whom:					Erwin Lansing <erwin@lansing.dk>
#
# $FreeBSD$
#

PORTNAME=	CGI-Session
PORTVERSION=	2.94
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		CGI::Session::DB_File.3 \
		CGI::Session::MySQL.3 \
		CGI::Session::MD5.3 \
		CGI::Session::File.3

.include <bsd.port.mk>
