# New ports collection makefile for:   smtp-gated
# Date created:        1 January 2006
# Whom:                msciciel
#
# $FreeBSD$
#

PORTNAME=	smtp-gated
PORTVERSION=	1.4.18.8
CATEGORIES=	mail
MASTER_SITES=	http://software.klolik.org/smtp-gated/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Proxy for SMTP sessions with virus and spam scan

LICENSE=	GPLv2

OPTIONS=	NAT "NAT transparent proxy code" On \
		CHUNKING "Enable support for SMTP CHUNKING extension" Off \
		ECONNRESET "Be quiet about Connection reset by peer message" Off \
		PCRE "Enable support for PCRE" On

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN5=		smtp-gated.conf.5
MAN8=		smtp-gated.8
PLIST_FILES=	sbin/smtp-gated

.include <bsd.port.options.mk>

.if defined(WITH_NAT)
CONFIGURE_ARGS+=	--enable-nat
.else
CONFIGURE_ARGS+=	--disable-nat
.endif

.if defined(WITH_CHUNKING)
CONFIGURE_ARGS+=	--enable-chunking
.endif

.if defined(WITH_ECONNRESET)
CONFIGURE_ARGS+=	--enable-silent-econnreset
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.1:${PORTSDIR}/devel/pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc: cannot determine endianness
.endif

.include <bsd.port.post.mk>
