# ex:ts=8
# New ports collection makefile for:	libxml++
# Date created:			Feb 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxml++
PORTVERSION=	0.27.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/+/plus/g}

MAINTAINER=	bland@FreeBSD.org
COMMENT=	XML API for C++

USE_GNOME=	gnomehack gnometarget libxml2 pkgconfig
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
