# New ports collection makefile for:	gkrellmwho2
# Date created:        	12 Nov 2003
# Whom:            	Alexey Zaytsev
#
# $FreeBSD$
#

PORTNAME=	gkrellmwho2
PORTVERSION=	0.2.8
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://shisha.spb.ru/ \
		http://users.podolsk.ru/c104598/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	mangoost@inetcomm.ru
COMMENT=	Displays logged in users

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

ALL_TARGET=
PLIST_FILES=	libexec/gkrellm2/plugins/gkrellmwho2.so

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gkrellmwho2.so ${PREFIX}/libexec/gkrellm2/plugins/

.include <bsd.port.mk>
