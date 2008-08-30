# New ports collection makefile for:	p5-HTML-Template
# Date Created:				26 Oct, 2000
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-Template
PORTVERSION=	2.9
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module to use HTML Templates from CGI scripts

PERL_CONFIGURE=	yes

MAN3=		HTML::Template.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable
.endif

.include <bsd.port.post.mk>
