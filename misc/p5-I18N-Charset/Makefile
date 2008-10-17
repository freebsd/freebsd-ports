# New ports collection makefile for:    p5-I18N-Charset
# Date created:			26 December 1999
# Whom:	      			Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	I18N-Charset
PORTVERSION=	1.39.4
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/\1/}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Module which maps CharSet names to the names registered with IANA

BUILD_DEPENDS=	p5-IO-Capture>=0:${PORTSDIR}/devel/p5-IO-Capture
RUN_DEPENDS=	p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-Unicode-MapUTF8>=0:${PORTSDIR}/converters/p5-Unicode-MapUTF8

PERL_CONFIGURE=	YES

MAN3=		I18N::Charset.3

.include <bsd.port.mk>
