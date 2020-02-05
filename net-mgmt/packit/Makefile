# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	packit
PORTVERSION=	1.7
CATEGORIES=	net-mgmt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Network auditing tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnet.so:net/libnet

USES=		autoreconf localbase
USE_GITHUB=	yes
GH_ACCOUNT=	eribertomota

GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/packit \
		man/man8/packit.8.gz

OPTIONS_DEFINE=	CAPTURE INJECTION

CAPTURE_DESC=	Capture support
INJECTION_DESC=	Injection support

OPTIONS_DEFAULT=CAPTURE INJECTION

CAPTURE_CONFIGURE_OFF=		--without-capture
INJECTION_CONFIGURE_OFF=	--without-injection

.include <bsd.port.mk>
