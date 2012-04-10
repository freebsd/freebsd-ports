# New ports collection makefile for:	p5-Search-Estraier
# Date created:		2006-07-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Search-Estraier
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Pure perl module to use Hyper Estraier search engine

BUILD_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=		Search::Estraier.3

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/bin

.include <bsd.port.mk>
