# New ports collection makefile for:	mod_snake
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_snake
PORTVERSION=	0.5.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	modsnake

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13 \
		${PYTHON_CMD}:${PYTHON_PORTSDIR}
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
APXS?=		${LOCALBASE}/sbin/apxs
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apxs="${APXS}"
USE_GMAKE=	yes

.include <bsd.port.mk>
