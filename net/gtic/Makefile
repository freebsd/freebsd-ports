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
		ftp://ftp.kspu.kr.ua/pub/unix/FIDO/gtic/ \
		ftp://ftp.ns.burnet.ru/pub/fido/gtic/ \
		ftp://ftp.3logic.net/pub/Linux/fido/ \
		ftp://ftp.braz.ru/pub/fido/gtic/
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
