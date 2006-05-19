# New ports collection makefile for:	sarg
# Date created:		23.02.2003
# Whom:			mt@primats.org.ua
#
# $FreeBSD$
#

PORTNAME=	sarg
PORTVERSION=	2.2.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Squid log analyzer and HTML report generator

OPTIONS=	GD "Enable GD support" on

USE_ICONV=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CC=gcc CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-bindir="${PREFIX}/bin" \
		--enable-sysconfdir="${PREFIX}/etc/${PORTNAME}" \
		--enable-htmldir="${PREFIX}/www/${PORTNAME}" \
		--enable-mandir="${MAN1PREFIX}/man/man1"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		sarg.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GD)
GD_PORT?=	graphics/gd
LIB_DEPENDS+=	gd.4:${PORTSDIR}/${GD_PORT}
.endif

post-extract:
	@${CHMOD} +x ${WRKSRC}/sarg-php/locale

post-patch:
	@${REINPLACE_CMD} -e '/^LDFLAGS=/d' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
