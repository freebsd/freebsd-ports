# $FreeBSD$

PORTNAME=	HTML-FormatExternal
PORTVERSION=	24
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML to text formatting using external programs

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-IPC-Run>0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-URI>=0.08:${PORTSDIR}/net/p5-URI \
		p5-constant-defer>=0:${PORTSDIR}/devel/p5-constant-defer
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	ELINKS HTML2TEXT LINKS LYNX LYNX_CURRENT NETRIK W3M
OPTIONS_DEFAULT=LYNX

INSTALL_TARGET=	pure_install
NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

ELINKS_DESC=		Install with elinks
ELINKS_RUN_DEPENDS=	elinks:${PORTSDIR}/www/elinks
HTML2TEXT_DESC=		Install with html2text
HTML2TEXT_RUN_DEPENDS=	html2text:${PORTSDIR}/textproc/html2text
LINKS_DESC=		Install with links
LINKS_RUN_DEPENDS=	links:${PORTSDIR}/www/links
LYNX_DESC=		Install with lynx
LYNX_RUN_DEPENDS=	lynx:${PORTSDIR}/www/lynx
LYNX_CURRENT_DESC=	Install with lynx-current
LYNX_CURRENT_RUN_DEPENDS=	lynx:${PORTSDIR}/www/lynx-current
NETRIK_DESC=		Install with netrik
NETRIK_RUN_DEPENDS=	netrik:${PORTSDIR}/www/netrik
W3M_DESC=		Install with w3m
W3M_RUN_DEPENDS=	w3m:${PORTSDIR}/www/w3m

.include <bsd.port.mk>
