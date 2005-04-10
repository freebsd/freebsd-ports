# New ports collection makefile for:	osb-nrcit
# Date created:		2004-11-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osb-nrcit
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk-webcore

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Embeddable web component using KJS, KHTML and KWIQ

LIB_DEPENDS=	nrcore.0:${PORTSDIR}/www/osb-nrcore \
		curl.3:${PORTSDIR}/ftp/curl

USE_GNOME=	gtk20 gnomehack
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
BROKEN=		"Does not compile on !i386 and !amd64"
.endif

.include <bsd.port.post.mk>
