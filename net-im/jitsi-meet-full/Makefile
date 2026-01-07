PORTNAME=	jitsi-meet-full
PORTVERSION=	2.0.9955
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	acm@FreeBSD.org
COMMENT=	All components to run Jitsi Meet video conferencing
WWW=		https://jitsi.org/jitsi-meet/

USES=		metaport

RUN_DEPENDS+=	jicofo>=1.0.1118:net-im/jicofo \
		jitsi-meet>=1.0.8339:www/jitsi-meet \
		jitsi-prosody-plugins>=2.0.9955:net-im/jitsi-prosody-plugins \
		jitsi-srtp-native>=1.1.18:net-im/jitsi-srtp-native \
		jitsi-videobridge>=2.3.198:net-im/jitsi-videobridge \
		nginx>0:www/nginx

.include <bsd.port.mk>
