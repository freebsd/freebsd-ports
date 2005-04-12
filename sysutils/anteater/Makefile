# ex:ts=8
# New ports collection makefile for:	anteater
# Date created:			Aug 13, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	anteater
PORTVERSION=	0.4.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A MTA log analyzer

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		anteater.1
PLIST_FILES=	bin/anteater

.include <bsd.port.mk>
