# New ports collection makefile for:	p5-HTML-Template-JIT
# Date Created:				2004/04/30
# Whom:					alex@kapranoff.ru
#
# $FreeBSD$
#

PORTNAME=	HTML-Template-JIT
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl module to compile HTML Templates with Inline::C

BUILD_DEPENDS=	${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Inline/C.pm:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::Template::JIT.3 HTML::Template::JIT::Compiler.3 \
		HTML::Template::JIT::Base.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES=	${PATCHDIR}/5.005-JIT-Compiler.pm
post-patch:
	@${PERL} -i -pe '$$_ = "" if /warnings|5\.006/g;' \
			-e 's/\bour ([^ ;]+)/use vars qw{$$1};$$1/g;' \
			${WRKSRC}/Makefile.PL ${WRKSRC}/JIT.pm \
			${WRKSRC}/JIT/Base.pm ${WRKSRC}/JIT/Compiler.pm
.endif

.include <bsd.port.post.mk>
