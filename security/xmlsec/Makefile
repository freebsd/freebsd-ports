# ex:ts=8
# Ports collection makefile for:	xmlsec
# Date created:			Jul 31, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlsec
PORTVERSION=	0.0.10
CATEGORIES=	security
MASTER_SITES=	http://www.aleksey.com/xmlsec/download/

MAINTAINER=	jim@corebsd.or.id

LIB_DEPENDS=	xslt:${PORTSDIR}/textproc/libxslt

USE_OPENSSL=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

MAN1=	xmlsec.1 xmlsec-config.1

.include <bsd.port.mk>
