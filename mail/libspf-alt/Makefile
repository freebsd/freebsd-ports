# New ports collection makefile for:	mailutils
# Date created:				26 May 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=		libspf-alt
PORTVERSION=		0.4.0
CATEGORIES=		mail devel
MASTER_SITES=		http://www.midwestcs.com/spf/%SUBDIR%/
MASTER_SITE_SUBDIR=	libspf-alt
DISTNAME=		libspf_alt-${PORTVERSION}

MAINTAINER=		eik@FreeBSD.org
COMMENT=		Library that allows email systems such as Exim to check SPF records

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

.include <bsd.port.mk>
