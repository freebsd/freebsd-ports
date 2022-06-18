PORTNAME=	jitsi-meet-full
PORTVERSION=	2.0.7287
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	acm@FreeBSD.org
COMMENT=	All components to run Jitsi Meet video conferencing

USES=		metaport

RUN_DEPENDS+=	jicofo>=1.0.877:net-im/jicofo \
		jitsi-meet>=1.0.6155:www/jitsi-meet \
		jitsi-prosody-plugins>=2.0.7287:net-im/jitsi-prosody-plugins \
		jitsi-srtp-native>=1.1.7:net-im/jitsi-srtp-native \
		jitsi-videobridge>=2.1.681:net-im/jitsi-videobridge \
		nginx>0:www/nginx

.include <bsd.port.mk>
