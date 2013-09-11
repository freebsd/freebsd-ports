# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	CSS-Compressor
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl extension for CSS minification

USES=		perl5
USE_PERL5=	configure

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/csscompressor ${PREFIX}/bin

MAN3=		CSS::Compressor.3

.include <bsd.port.mk>
