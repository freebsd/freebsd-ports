# New ports collection makefile for:	libspf-alt
# Date created:				28 February 2004
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=		libspf-alt
PORTVERSION=		0.4.0
PORTREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://libspf2.org/spf/
DISTNAME=		libspf_alt-${PORTVERSION}

MAINTAINER=		daniel@roe.ch
COMMENT=		Library that allows email systems such as Exim to check SPF records

DEPRECATED=		Superceded by mail/libspf2

GNU_CONFIGURE=		yes
USE_ICONV=		yes
USE_GETTEXT=		yes
INSTALLS_SHLIB=		yes

CPPFLAGS+=		${PTHREAD_CFLAGS} \
			-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" \
			LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=		--program-transform-name=s,^spf,spf_alt,

.include <bsd.port.mk>
