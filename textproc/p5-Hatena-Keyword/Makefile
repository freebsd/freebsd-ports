# New ports collection makefile for:	p5-Hatena-Keyword
# Date created:		2006-09-02
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	Hatena-Keyword
PORTVERSION=	0.04
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/N/NA/NAOYA
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Extract Hatena Keywords in a string

BUILD_DEPENDS=	${SITE_PERL}/RPC/XML.pm:${PORTSDIR}/net/p5-RPC-XML \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Class/ErrorHandler.pm:${PORTSDIR}/devel/p5-Class-ErrorHandler \
		${SITE_PERL}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Hatena::Keyword.3

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
