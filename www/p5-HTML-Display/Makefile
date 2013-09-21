# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTML-Display
PORTVERSION=	0.40
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Display HTML locally in a browser

RUN_DEPENDS=	p5-HTML-TokeParser-Simple>=2:${PORTSDIR}/www/p5-HTML-TokeParser-Simple \
		p5-libwww>=5.69:${PORTSDIR}/www/p5-libwww \
		p5-parent>=0.218:${PORTSDIR}/devel/p5-parent \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-Test-Harness>=2.30:${PORTSDIR}/devel/p5-Test-Harness

USES=		perl5
USE_PERL5=	configure

MAN3=	HTML::Display.3 \
	HTML::Display::Common.3 \
	HTML::Display::Debian.3 \
	HTML::Display::Dump.3 \
	HTML::Display::Galeon.3 \
	HTML::Display::Mozilla.3 \
	HTML::Display::OSX.3 \
	HTML::Display::Opera.3 \
	HTML::Display::Phoenix.3 \
	HTML::Display::TempFile.3 \
	HTML::Display::Win32.3 \
	HTML::Display::Win32::IE.3 \
	HTML::Display::Win32::OLE.3

NO_STAGE=	yes

regression-test:
	@${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
