# $FreeBSD$

PORTNAME=	Ark
PORTVERSION=	0.1.r1
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	GHC LOCAL/kuriyama
PKGNAMEPREFIX=	p5-
DISTNAME=	Ark-0.001000_001

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl web application framework

BUILD_DEPENDS:=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-Class-Data-Inheritable>0:devel/p5-Class-Data-Inheritable \
	p5-Class-Method-Modifiers-Fast>0:devel/p5-Class-Method-Modifiers-Fast \
	p5-Data-UUID>0:devel/p5-Data-UUID \
	p5-Data-Util>0:devel/p5-Data-Util \
	p5-Devel-StackTrace>0:devel/p5-Devel-StackTrace \
	p5-Digest-SHA1>0:security/p5-Digest-SHA1 \
	p5-FindBin-libs>0:devel/p5-FindBin-libs \
	p5-HTML-Parser>0:www/p5-HTML-Parser \
	p5-HTTP-Engine>=0.1.8:www/p5-HTTP-Engine \
	p5-HTTP-Engine-Middleware>=0.13:www/p5-HTTP-Engine-Middleware \
	p5-MIME-Types>0:mail/p5-MIME-Types \
	p5-Module-Setup>0:devel/p5-Module-Setup \
	p5-Mouse>=0.21:devel/p5-Mouse \
	p5-MouseX-Types-Path-Class>0:devel/p5-MouseX-Types-Path-Class \
	p5-Path-Class>=0.16:devel/p5-Path-Class \
	p5-Text-SimpleTable>=0.05:textproc/p5-Text-SimpleTable \
	p5-URI>0:net/p5-URI

USES=		perl5
USE_PERL5=	configure
USE_GITHUB=	yes
GH_ACCOUNT=	typester
GH_PROJECT=	ark-perl
WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.mk>
