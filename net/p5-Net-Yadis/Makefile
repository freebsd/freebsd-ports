# New ports collection makefile for:	p5-Net-Yadis
# Date created:		2006-12-19
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Yadis
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Yadis service discovery protocol, and parses XRDS xml documents

RUN_DEPENDS=	${SITE_PERL}/XML/XPath.pm:${PORTSDIR}/textproc/p5-XML-XPath \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Yadis.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# Inherited from www/p5-libwww
IGNORE=		requires Perl 5.6 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
