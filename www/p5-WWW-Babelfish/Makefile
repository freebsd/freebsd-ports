# New ports collection makefile for:	WWW-Babelfish
# Date created:				Wed Jan  3 08:00:30 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	WWW-Babelfish
PORTVERSION=	0.16
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to obtain translations from the babelfish server

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Babelfish.3

.include <bsd.port.mk>
