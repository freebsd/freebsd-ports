# New ports collection makefile for:   etherboot
# Date created:        16 April 1999
# Whom:                Doug Ambrisko <ambrisko@whistle.com>
#
# $FreeBSD$
#

PORTNAME=	etherboot
PORTVERSION=	4.6.10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ambrisko@whistle.com

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

NO_PACKAGE=	lots of configuration necessary
USE_GMAKE=1
WRKSRC=		${WRKDIR}/${DISTNAME}/src

do-install:
	@${ECHO} Refer ${DESCR} and ${WRKDIR}/${PKGNAME}/doc for how to
	@${ECHO} build and install the rom/floppy image.
	@exit 1

.include <bsd.port.mk>
