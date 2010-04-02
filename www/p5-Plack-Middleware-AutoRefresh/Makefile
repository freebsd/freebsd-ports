# New ports collection makefile for:	Plack::Middleware::AutoRefresh
# Date created:		02 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Middleware-AutoRefresh
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to reload pages when files are modified

RUN_DEPENDS=	\
	p5-AnyEvent>0:${PORTSDIR}/devel/p5-AnyEvent \
	p5-AnyEvent-Filesys-Notify>=0:${PORTSDIR}/devel/p5-AnyEvent-Filesys-Notify \
	p5-File-ShareDir>=1.00:${PORTSDIR}/devel/p5-File-ShareDir \
	p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp \
	p5-JSON-Any>0:${PORTSDIR}/converters/p5-JSON-Any \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-Readonly>0:${PORTSDIR}/devel/p5-Readonly
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Plack::Middleware::AutoRefresh.3

.include <bsd.port.mk>
