# New ports collection makefile for:	ksig
# Date created:			Tue Aug 19 13:33:32 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		ksig
PORTVERSION=		0.1
PORTREVISION=	1
CATEGORIES=		mail kde
MASTER_SITES=		http://www.slackorama.net/oss/ksig/

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		Tool for managing a collection of e-mail signatures

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
