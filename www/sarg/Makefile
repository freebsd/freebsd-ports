# New ports collection makefile for:	sarg
# Date created:		23.02.2003
# Whom:			mt@primats.org.ua
#
# $FreeBSD$
#

PORTNAME=	sarg
PORTVERSION=	2.0.8
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mt@primats.org.ua
COMMENT=	Squid log analyzer and HTML report generator

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC=gcc
CONFIGURE_ARGS=	--enable-bindir="${PREFIX}/bin" \
		--enable-sysconfdir="${PREFIX}/etc/${PORTNAME}" \
		--enable-htmldir="${PREFIX}/www/${PORTNAME}" \
		--enable-mandir="${MAN1PREFIX}/man/man1"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if !defined(WITHOUT_GD)
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
.endif

MAN1=		sarg.1

post-extract:
	@${CHMOD} +x ${WRKSRC}/sarg-php/locale

post-patch:
	@${REINPLACE_CMD} -e '/^LDFLAGS/d' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
