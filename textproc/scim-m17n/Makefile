# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	scim-m17n
PORTVERSION=	0.2.3
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	SCIM IMEngine module which uses m17n library as the backend

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim \
		gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS=	m17n.4:${PORTSDIR}/devel/m17n-lib
RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
