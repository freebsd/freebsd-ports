# New ports collection makefile for:	gtkstep-pastel
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkstep-pastel
PORTVERSION= 	0.9.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lab/8325/
DISTNAME=	${PORTNAME}-${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

DISTVERSION=	0_9_0
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
