PORTNAME=	sie-nmsg
PORTVERSION=	1.3.1
PORTREVISION=	4
CATEGORIES=	net dns

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	SIE message module plugin for libnmsg
WWW=		https://github.com/farsightsec/sie-nmsg

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libprotobuf-c.so:devel/protobuf-c \
		libnmsg.so:net/nmsg \
		libwdns.so:dns/wdns

GNU_CONFIGURE=	yes
USES=	autoreconf gmake libtool pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	farsightsec

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
