# New ports collection makefile for:	di
# Date created:			31 August 2002
# Whom:				Brad Lanam <bll@gentoo.com>
#
# $FreeBSD$
#

PORTNAME=	di
PORTVERSION=	3.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.gentoo.com/di/

MAINTAINER=	bll@gentoo.com
COMMENT=	A disk information utility

HAS_CONFIGURE=	yes
MAN1=		di.1

.include <bsd.port.pre.mk>

do-configure:
	(cd ${WRKSRC}; \
		CC="$(CC)" CFLAGS="$(CFLAGS)" \
		LDFLAGS="$(LDFLAGS)" prefix="$(PREFIX)" ./Build config.h)

do-build:
	(cd ${WRKSRC}; \
		CC="$(CC)" CFLAGS="$(CFLAGS)" \
		LDFLAGS="$(LDFLAGS)" prefix="$(PREFIX)" ./Build)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/di ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mi ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/di.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
