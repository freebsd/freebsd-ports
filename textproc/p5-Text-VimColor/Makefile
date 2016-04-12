# Created by: Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
# $FreeBSD$

PORTNAME=	Text-VimColor
PORTVERSION=	0.26
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Syntax color text in HTML or XML using Vim

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install \
		p5-Path-Class>=0:devel/p5-Path-Class \
		vim:editors/vim
RUN_DEPENDS=	p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-Path-Class>=0:devel/p5-Path-Class \
		vim:editors/vim
TEST_DEPENDS=	p5-Test-File-ShareDir>=0:devel/p5-Test-File-ShareDir \
		p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e '/use inc::VimCommand/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
