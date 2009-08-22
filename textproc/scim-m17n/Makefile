# New ports collection makefile for:	scim-m17n
# Date Created:				10 May 2007
# Whom:					Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	scim-m17n
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/


MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	A SCIM IMEngine module which uses m17n library as the backend

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim \
		gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS=	m17n.3:${PORTSDIR}/devel/m17n-lib
RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
