# New ports collection makefile for:	mhash
# Date created:		Mon Jun 28 17:59:13 PDT 1999
# Whom:			nsayer@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	mhash
PORTVERSION=	0.8.18
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	"Library provides an easy way to access strong hashes such as MD5 and SHA1"

INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-LDFLAGS="${PTHREAD_LIBS}" --enable-static \
			--with-gnu-ld

MAN3=		mhash.3

.include <bsd.port.mk>
