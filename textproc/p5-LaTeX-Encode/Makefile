# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	LaTeX-Encode
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Encode characters for LaTeX formatting

PERL_CONFIGURE=	yes

RUN_DEPENDS=	p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly
BUILD_DEPENDS:=	${RUN_DEPENDS}

MAN1=	latex-encode.1
MAN3=	LaTeX::Encode.3 LaTeX::Encode::EncodingTable.3

.include <bsd.port.mk>
