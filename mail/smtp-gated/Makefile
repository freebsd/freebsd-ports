# Created by: msciciel
# $FreeBSD$

PORTNAME=	smtp-gated
PORTVERSION=	1.4.20.0
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://software.klolik.org/smtp-gated/files/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Proxy for SMTP sessions with virus and spam scan

BROKEN=		unfetchable

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	sbin/smtp-gated \
		man/man5/smtp-gated.conf.5.gz \
		man/man8/smtp-gated.8.gz

OPTIONS_DEFINE=	NAT CHUNKING ECONNRESET PCRE
OPTIONS_DEFAULT=	NAT PCRE

NAT_DESC=	NAT transparent proxy code
CHUNKING_DESC=	SMTP CHUNKING extension support
ECONNRESET_DESC=	Be quiet about "Connection reset by peer" message

NAT_CONFIGURE_ENABLE=	nat
CHUNKING_CONFIGURE_ENABLE=	chunking
ECONNRESET_CONFIGURE_ENABLE=	silent-econnreset
PCRE_CONFIGURE_OFF=	--disable-pcre
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

.include <bsd.port.mk>
