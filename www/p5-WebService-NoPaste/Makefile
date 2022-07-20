PORTNAME=	WebService-NoPaste
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pastebin web application to upload snippets of text

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-All>=0:devel/p5-IO-All \
		p5-Spiffy>=0:devel/p5-Spiffy \
		p5-libwww>=0:www/p5-libwww

USES=		perl5 shebangfix
USE_PERL5=	configure

NO_ARCH=	yes

SHEBANG_FILES=	nopaste

OPTIONS_DEFINE=	X11
X11_DESC=	X11 Clipboard support

X11_BUILD_DEPENDS=	p5-Clipboard>=0:x11/p5-Clipboard
X11_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-lib-WebService-NoPaste.pm

post-patch-X11-off:
	@${RM} ${WRKSRC}/lib/WebService/NoPaste.pm.orig

.include <bsd.port.mk>
