PORTNAME=	jitsi-meet-full
PORTVERSION=	2.0.8319
CATEGORIES=	net-im

MAINTAINER=	acm@FreeBSD.org
COMMENT=	All components to run Jitsi Meet video conferencing
WWW=		https://jitsi.org/jitsi-meet/

USES=		metaport

RUN_DEPENDS+=	jicofo>=1.0.996:net-im/jicofo \
		jitsi-meet>=1.0.6991:www/jitsi-meet \
		jitsi-prosody-plugins>=2.0.8319:net-im/jitsi-prosody-plugins \
		jitsi-srtp-native>=1.1.8:net-im/jitsi-srtp-native \
		jitsi-videobridge>=2.2.79:net-im/jitsi-videobridge \
		nginx>0:www/nginx

.include <bsd.port.mk>
