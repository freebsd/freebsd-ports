# New ports collection makefile for:	mdf2iso
# Date created:		2005-05-23
# Whom:			Andrej Zverev <az@inec.ru>
#
# $FreeBSD$
#

PORTNAME=	mdf2iso
PORTVERSION=	0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	az@inec.ru
COMMENT=	A Alcohol 120% to ISO converter

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/mdf2iso

.include <bsd.port.mk>
