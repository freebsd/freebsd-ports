# New ports collection makefile for:	p5-Acme-Monta
# Date created:				14 June 2005
# Whom:	      				TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Acme-Monta
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Acme
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Monta Method reproduced in web

PERL_CONFIGURE=	yes

MAN3=		Acme::Monta.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars qw($$1); $$1/' \
		${WRKSRC}/lib/Acme/Monta.pm
.endif

.include <bsd.port.post.mk>
