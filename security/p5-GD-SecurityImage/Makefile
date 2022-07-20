PORTNAME=	GD-SecurityImage
PORTVERSION=	1.75
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for creating CAPTCHA security images

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-GD>=2.45:graphics/p5-GD

OPTIONS_DEFINE=	IMAGEMAGICK X11
OPTIONS_DEFAULT=X11
IMAGEMAGICK_DESC=	Build ImageMagick module

PORTSCOUT=	skipv:1.581

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGEMAGICK}
.if ${PORT_OPTIONS:MX11}
USES+=		magick:6,build,run
.else
USES+=		magick:6,build,run,nox11
.endif
.endif

.include <bsd.port.mk>
