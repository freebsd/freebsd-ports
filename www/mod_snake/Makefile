# New ports collection makefile for:	mod_snake
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_snake
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	modsnake

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A library to easily create flexible Apache modules

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/${APACHE_PORT} \
		${PYTHON_CMD}:${PYTHON_PORTSDIR}
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apxs="${APXS}"
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		"Does not compile on amd64 or ia64"
.endif

.include <bsd.port.post.mk>
