# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PPI-HTML
PORTVERSION=	1.08
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Generate syntax-highlighted HTML for Perl using PPI

BUILD_DEPENDS=	p5-PPI>=0.990:${PORTSDIR}/textproc/p5-PPI \
		p5-CSS-Tiny>=0.10:${PORTSDIR}/textproc/p5-CSS-Tiny \
		p5-Params-Util>=0.05:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	PPI::HTML.3

post-patch:
	@${REINPLACE_CMD} -i '' '/Test::More/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
