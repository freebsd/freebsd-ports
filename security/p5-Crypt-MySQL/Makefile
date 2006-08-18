# New ports collection Makefile for:	p5-Crypt-MySQL
# Date created:				17 Dec 2006
# Whom:	      				Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-MySQL
PORTVERSION=	0.04
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	Perl extension to compare MySQL passwords without libmysqlclient

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1

PERL_MODBUILD=	yes

MAN3=		Crypt::MySQL.3

.include <bsd.port.mk>
