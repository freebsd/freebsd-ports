# New ports collection makefile for:	p5-News-Newsrc
# Date created:		February 7, 1998
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	News-Newsrc
PORTVERSION=	1.08
CATEGORIES=	news perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	News
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Manage newsrc files

BUILD_DEPENDS=	${SITE_PERL}/Set/IntSpan.pm:${PORTSDIR}/math/p5-Set-IntSpan
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		News::Newsrc.3

pre-patch:
	@${PERL} -pi -e '$$_ = "" if /^use 5.6/' ${WRKSRC}/Newsrc.pm

.include <bsd.port.mk>
