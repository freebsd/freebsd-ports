# ex:ts=8
# Ports collection makefile for:	mcron
# Date created:			Dec 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mcron
PORTVERSION=	1.0.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	mcron

MAINTAINER=	stefan@fh-mainz.de
COMMENT=	A 100% compatible replacement for Vixie cron

BUILD_DEPENDS=	guile>=1.6.4:${PORTSDIR}/lang/guile
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
MAKEFILE=	makefile

INFO=		mcron

# replacement only needed for 1.0.2 - 'mkinstalldirs' will be back in 1.0.3
post-patch:
	@${REINPLACE_CMD} 's|./mkinstalldirs|${MKDIR}|g' ${WRKSRC}/makefile.in

.include <bsd.port.mk>
