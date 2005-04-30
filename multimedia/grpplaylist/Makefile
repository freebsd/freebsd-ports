# New ports collection makefile for:	grpplaylist
# Date created:				Fri May  7 13:17:54 CEST 2004
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	grpplaylist
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	groupplaylist-${PORTVERSION}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	A playlist for Noatun

LIB_DEPENDS=	noatun:${PORTSDIR}/multimedia/kdemultimedia3

USE_KDEBASE_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|-fPIC|g' -e "s,-lpthread,${PTHREAD_LIBS},g" \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
