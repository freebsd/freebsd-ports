# ex:ts=8
# Ports collection makefile for:  smtp-vilter
# Date created:			  17.1.2004
# Whom:				  Danuel Mueller + Martin Blapp, ImproWare AG
#
# $FreeBSD$
#

PORTNAME=	smtp-vilter
PORTVERSION=	1.1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.etc.msys.ch/software/smtp-vilter/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	spam/virus filter infrastructure

BROKEN=		"Checksum mismatch"

MAKEFILE=	Makefile.freebsd

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_TARGET=${ARCH}-portbld-freebsd${OSREL}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=

.include <bsd.port.mk>
