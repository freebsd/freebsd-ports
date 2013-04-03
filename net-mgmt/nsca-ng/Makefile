# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	nsca-ng
PORTVERSION=	1.0
#PORTREVISION=	0
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.nsca-ng.org/download/

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	NSCA alternative

LIB_DEPENDS=	confuse:${PORTSDIR}/devel/libconfuse \
				ev:${PORTSDIR}/devel/libev

CONFLICTS=	nsca-[0-9]*
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-server \
					--disable-client \
					--mandir=${LOCALBASE}/man \
					--with-confuse=${LOCALBASE} \
					--with-ev=${LOCALBASE} \
					--with-openssl=${OPENSSLBASE}
USE_OPENSSL=	yes
USE_OPENSSL_PORT=	yes
MANCOMPRESSED=	no
MAN5=	nsca-ng.cfg.5 \
		send_nsca.cfg.5
MAN8=	nsca-ng.8 \
		send_nsca.8


.include <bsd.port.mk>
