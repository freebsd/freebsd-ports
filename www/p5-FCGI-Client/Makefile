# New ports collection makefile for:	FCGI::Client
# Date created:		02 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	FCGI-Client
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for fastcgi protocol client library

RUN_DEPENDS=	\
	p5-Any-Moose>=0.1:${PORTSDIR}/devel/p5-Any-Moose \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	FCGI::Client.3 \
	FCGI::Client::Connection.3 \
	FCGI::Client::Constant.3 \
	FCGI::Client::Record.3 \
	FCGI::Client::RecordFactory.3 \
	FCGI::Client::RecordHeader.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 501000
RUN_DEPENDS+=	p5-autodie>0:${PORTSDIR}/devel/p5-autodie
.endif

.include <bsd.port.post.mk>
