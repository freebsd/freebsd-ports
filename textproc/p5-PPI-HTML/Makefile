# New ports collection makefile for:	textproc/p5-PPI-HTML
# Date created:				24 March 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PPI-HTML
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/A/AD/ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Generate syntax-hightlighted HTML for Perl using PPI

BUILD_DEPENDS=	${SITE_PERL}/PPI.pm:${PORTSDIR}/textproc/p5-PPI \
		${SITE_PERL}/CSS/Tiny.pm:${PORTSDIR}/textproc/p5-CSS-Tiny
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	PPI::HTML.3

post-patch:
	@${RM} ${WRKSRC}/inc/Module/Install/AutoInstall.pm
	@${PERL} -pi -e '$$_="" if m/AutoInstall/' ${WRKSRC}/MANIFEST
	@${PERL} -pi -e '$$_="" if m/Test::More|auto_install/' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
# version limitation inherited from textproc/p5-PPI
IGNORE=	requires Perl 5.6 or newer. Install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
