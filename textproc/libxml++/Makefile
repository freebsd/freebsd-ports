# ex:ts=8
# New ports collection makefile for:	libxml++
# Date created:			Feb 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxml++
PORTVERSION=	1.0.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	bland@FreeBSD.org
COMMENT=	XML API for C++

USE_GNOME=	gnomehack lthack gnometarget libxml2 pkgconfig
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
post-patch:
	@${FIND} ${WRKSRC}/libxml++ -name *.h \
		| ${XARGS} ${REINPLACE_CMD} -e \
			's|<ostream>|<iostream>|'

.endif

.include <bsd.port.post.mk>
