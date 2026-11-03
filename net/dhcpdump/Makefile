PORTNAME=	dhcpdump
DISTVERSIONPREFIX=	v
DISTVERSION=	2.00
CATEGORIES=	net

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Decode and diagnose sniffed DHCP packets
WWW=		https://github.com/dhcpdump-org/dhcpdump

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake perl5
USE_PERL5=	build
USE_GITHUB=	yes
GH_ACCOUNT=	dhcpdump-org

OPTIONS_DEFINE=	TUI
OPTIONS_DEFAULT=TUI

TUI_DESC=	Interactive session tracking interface (-t)

TUI_LIB_DEPENDS=	libyascreen.so:devel/yascreen
TUI_MAKE_ARGS_OFF=	NO_TUI=1
TUI_USES=		pkgconfig

PLIST_FILES=	bin/dhcpdump share/man/man8/dhcpdump.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhcpdump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dhcpdump.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
