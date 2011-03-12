# New ports collection makefile for:	p5-HTML-DOM
# Date created:				26 Jan 2010
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-DOM
PORTVERSION=	0.047
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Implementation of the HTML Document Object Model

RUN_DEPENDS=	p5-Hash-Util-FieldHash-Compat>=0:${PORTSDIR}/devel/p5-Hash-Util-FieldHash-Compat \
		p5-HTML-Element-Library>=0:${PORTSDIR}/www/p5-HTML-Element-Library \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-constant-lexical>0:${PORTSDIR}/devel/p5-constant-lexical
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

.include <bsd.port.pre.mk>
.include "${MASTERDIR}/Makefile.man"
.include <bsd.port.post.mk>
