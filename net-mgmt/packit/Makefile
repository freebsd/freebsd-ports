PORTNAME=	packit
DISTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Modern network auditing and packet crafting tool
WWW=		https://github.com/Obsidian-Covenant/packit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnet.so:net/libnet

USES=		autoreconf localbase
USE_GITHUB=	yes
GH_ACCOUNT=	Obsidian-Covenant

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/packit \
		share/man/man8/packit.8.gz

OPTIONS_DEFINE=		CAPTURE INJECTION
OPTIONS_DEFAULT=	CAPTURE INJECTION

CAPTURE_DESC=	Capture support
INJECTION_DESC=	Injection support

CAPTURE_CONFIGURE_OFF=		--without-capture
INJECTION_CONFIGURE_OFF=	--without-injection

.include <bsd.port.mk>
