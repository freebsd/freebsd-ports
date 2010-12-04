# New ports collection makefile for:   smtp-gated
# Date created:        1 January 2006
# Whom:                msciciel
#
# $FreeBSD$
#

PORTNAME=	smtp-gated
PORTVERSION=	1.4.16.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://software.klolik.org/smtp-gated/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	This software block SMTP sessions used by e-mail worms and viruses

HAS_CONFIGURE=	yes
USE_AUTOTOOLS=	autoheader

OPTIONS=	NAT "NAT transparent proxy code" On \
		CHUNKING "Enable support for SMTP CHUNKING extension" Off \
		ECONNRESET "Be quiet about Connection reset by peer message" Off

PLIST_FILES=	sbin/smtp-gated
MAN5=		smtp-gated.conf.5
MAN8=		smtp-gated.8

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc: cannot determine endianness
.endif

post-patch:
	${REINPLACE_CMD} -e 's,install-man: install-man5 install-man8 install-manh,install-man: install-man5 install-man8,' ${WRKSRC}/doc/Makefile.in

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

.include <bsd.port.post.mk>
