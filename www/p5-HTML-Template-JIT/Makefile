# Created by: alex@kapranoff.ru
# $FreeBSD$

PORTNAME=	HTML-Template-JIT
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to compile HTML Templates with Inline::C

BUILD_DEPENDS=	p5-HTML-Template>=2.8:${PORTSDIR}/www/p5-HTML-Template \
		p5-Inline>=0.43:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		HTML::Template::JIT.3 HTML::Template::JIT::Compiler.3 \
		HTML::Template::JIT::Base.3

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -i '' -e 's/indent -kr/indent/' \
			${WRKSRC}/JIT/Compiler.pm

.include <bsd.port.post.mk>
