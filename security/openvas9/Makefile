# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openvas9
PORTVERSION=	9.0
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	acm@FreeBSD.org
COMMENT=	openvas 9 vulnerability scanner (metaport)

USES=		metaport

# Install OpenVAS libraries
RUN_DEPENDS+=	${LOCALBASE}/lib/libopenvas_base.so:security/openvas${OPENVAS_VER}-libraries

# Install OpenVAS Commnad Line
RUN_DEPENDS+=	${LOCALBASE}/bin/omp:security/openvas${OPENVAS_VER}-cli

# Install OpenVAS Manager
RUN_DEPENDS+=	${LOCALBASE}/sbin/openvasmd:security/openvas${OPENVAS_VER}-manager

# Install OpenVAS Scanner
RUN_DEPENDS+=	${LOCALBASE}/sbin/openvassd:security/openvas${OPENVAS_VER}-scanner

# Install OpenVAS Web Interface
RUN_DEPENDS+=	${LOCALBASE}/sbin/gsad:security/greenbone-security-assistant${OPENVAS_VER}

SUB_FILES=	pkg-message
OPENVAS_VER=	9

.include <bsd.port.mk>
