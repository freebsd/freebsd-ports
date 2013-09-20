# Created by: msciciel
# $FreeBSD$

PORTNAME=	smtp-gated
PORTVERSION=	1.4.20.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://software.klolik.org/smtp-gated/files/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Proxy for SMTP sessions with virus and spam scan

LICENSE=	GPLv2

OPTIONS_DEFINE=	NAT CHUNKING ECONNRESET PCRE
OPTIONS_DEFAULT=	NAT PCRE
NAT_DESC=	NAT transparent proxy code
CHUNKING_DESC=	Enable support for SMTP CHUNKING extension
ECONNRESET_DESC=	Be quiet about Connection reset by peer message

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN5=		smtp-gated.conf.5
MAN8=		smtp-gated.8
PLIST_FILES=	sbin/smtp-gated

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNAT}
CONFIGURE_ARGS+=	--enable-nat
.else
CONFIGURE_ARGS+=	--disable-nat
.endif

.if ${PORT_OPTIONS:MCHUNKING}
CONFIGURE_ARGS+=	--enable-chunking
.endif

.if ${PORT_OPTIONS:MECONNRESET}
CONFIGURE_ARGS+=	--enable-silent-econnreset
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc: cannot determine endianness
.endif

.include <bsd.port.post.mk>
