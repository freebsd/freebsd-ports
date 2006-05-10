# New ports collection makefile for:   libspf2
# Date created:        07 July 2004
# Whom:                snowchyld
#
# $FreeBSD$
#

PORTNAME=	libspf2
PORTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.libspf2.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	spf

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Sender Rewriting Scheme 2 C Implementation

CONFLICTS=	${PORTNAME}-1.0.*

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure

.include <bsd.port.mk>
