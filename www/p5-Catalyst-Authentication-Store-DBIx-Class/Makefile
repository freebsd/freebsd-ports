# New ports collection makefile for:	p5-Catalyst-Authentication-Store-DBIx-Class
# Date created:				2008-09-18
# Whom:					Oleg Mamontov <oleg@mamontov.net>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Authentication-Store-DBIx-Class
PORTVERSION=	0.1200
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	A storage class for Catalyst Authentication using DBIx::Class

BUILD_DEPENDS=	p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class		\
		p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime	\
		p5-Catalyst-Plugin-Authentication>=0.10008:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
		p5-Catalyst-Model-DBIC-Schema>=0.18:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Schema \
		p5-List-MoreUtils>=0:$(PORTSDIR)/lang/p5-List-MoreUtils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Authentication::Store::DBIx::Class.3	\
		Catalyst::Authentication::Store::DBIx::Class::User.3 \
		Catalyst::Authentication::Realm::SimpleDB.3

.include <bsd.port.mk>
