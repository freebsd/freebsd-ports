# New ports collection makefile for:	gtic
# Date created:		22 August 1999
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	gtic
PORTVERSION=	1.3.b
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cracksoft.kiev.ua/pub/linux/gtic/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/fido
DISTNAME=	${PORTNAME}-1.3b

MAINTAINER=	dsh@vlink.ru

MAKE_ENV+=	DEFINES="${DEFINES}"

.if defined(WITH_AMIGA4D)
DEFINES+=	-DAMIGA4D
.endif

do-install:
	${MKDIR} ${PREFIX}/etc/gtic
.for i in areagroups areas config domains help users
	${INSTALL_DATA} ${WRKSRC}/etc/${i} ${PREFIX}/etc/gtic/${i}.sample
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/src/gtic ${PREFIX}/sbin/

.include <bsd.port.mk>
