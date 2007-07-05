# New ports collection makefile for:	scim-m17n
# Date Created:				10 May 2007
# Whom:					Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	scim-m17n
PORTVERSION=	0.2.2
CATEGORIES=	textproc
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=scim

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	A SCIM IMEngine module which uses m17n library as the backend

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	m17n.1:${PORTSDIR}/devel/m17n-lib
RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
