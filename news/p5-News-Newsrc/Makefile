# New ports collection makefile for:	p5-News-Newsrc
# Date created:		February 7, 1998
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	News-Newsrc
PORTVERSION=	1.09
CATEGORIES=	news perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manage newsrc files

BUILD_DEPENDS=	p5-Set-IntSpan>=0:${PORTSDIR}/math/p5-Set-IntSpan
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		News::Newsrc.3

pre-patch:
	@${PERL} -pi -e '$$_ = "" if /^use 5.6/' ${WRKSRC}/Newsrc.pm

.include <bsd.port.mk>
