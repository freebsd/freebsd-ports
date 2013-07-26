# Created by: Gea-Suan Lin <gslin@netnews.NCTU.edu.tw>
# $FreeBSD$

PORTNAME=	WebService-NoPaste
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	A pastebin web application to upload snippets of text

BUILD_DEPENDS=	p5-IO-All>=0:${PORTSDIR}/devel/p5-IO-All \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Spiffy>=0:${PORTSDIR}/devel/p5-Spiffy
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
USES=		shebangfix
SHEBANG_FILES=	nopaste

MAN3=		WebService::NoPaste.3

OPTIONS_DEFINE=	X11
X11_DESC=	X11 Clipboard support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
BUILD_DEPENDS+=	p5-Clipboard>=0:${PORTSDIR}/x11/p5-Clipboard
.else
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-lib-WebService-NoPaste.pm
.endif

post-patch:
.if ! ${PORT_OPTIONS:MX11}
	@${RM} ${WRKSRC}/lib/WebService/NoPaste.pm.orig
.endif

.include <bsd.port.mk>
