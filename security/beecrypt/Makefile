# ex:ts=8
# New ports collection makefile for:	beecrypt
# Date created:			Mar 4, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beecrypt
PORTVERSION=	4.2.1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	corky1951@comcast.net
COMMENT=	BeeCrypt is an open source cryptography library

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-java
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure
.if defined(WITH_OPENMP)
	@${ECHO_MSG} "Configuring for OpenMP support"
	@${ECHO_MSG} "Any ports depending on beecrypt must be configured for OpenMP too."

CONFIGURE_ARGS+=	--enable-openmp
.else
CONFIGURE_ARGS+=	--disable-openmp
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
