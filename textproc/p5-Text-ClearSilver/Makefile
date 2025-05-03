PORTNAME=	Text-ClearSilver
PORTVERSION=	0.10.5.4
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to the ClearSilver template engine
WWW=		https://metacpan.org/release/Text-ClearSilver

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

TEST_DEPENDS=	\
	p5-Test-Requires>0:devel/p5-Test-Requires \
	p5-Mouse>0:devel/p5-Mouse

USES=		perl5 gmake
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 503700
BROKEN=         uses hidden Perl functions that are hidden after 5.37.0
.endif

.include <bsd.port.post.mk>
