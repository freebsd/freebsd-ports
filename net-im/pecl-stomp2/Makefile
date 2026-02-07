PORTNAME=	stomp
DISTVERSION=	2.0.3
CATEGORIES=	net-im pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension of stomp client
WWW=		https://pecl.php.net/package/stomp

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:pecl
CONFLICTS=	pecl-stomp-1*

PORTSCOUT=	limit:^2.*

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
