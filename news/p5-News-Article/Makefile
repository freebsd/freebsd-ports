# New ports collection makefile for: p5-News-Article
# Date created: January 2, 1998
# Whom: Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	News-Article
PORTVERSION=	1.27
CATEGORIES=	news perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	News
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@freebsd.org
COMMENT=	Object for handling Usenet articles in mail or news form

RUN_DEPENDS=	${SITE_PERL}/Net/NNTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/PGP/Sign.pm:${PORTSDIR}/security/p5-PGP-Sign

PERL_CONFIGURE=	yes

MAN3=		News::Article.3 News::AutoReply.3 News::FormArticle.3 \
		News::FormReply.3

.include <bsd.port.mk>
