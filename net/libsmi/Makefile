# New ports collection makefile for:	libsmi
# Date created:			Tue Jan 27 2000
# Whom:				Marcin Cieslak <saper@system.pl>
#
# $FreeBSD$
#

PORTNAME=	libsmi
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/libsmi/

MAINTAINER=	saper@system.pl
COMMENT=	A library to access SMI MIB information

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
MIBDIR=		${PREFIX}/share/smi/mibs
CONFIGURE_ARGS+=--with-data-dir=${PREFIX}/share/smi \
		--with-mibdir=${MIBDIR}

MAN1=	smiquery.1 smilint.1 smidump.1 smistrip.1 smidiff.1 smicache.1
MAN3=	libsmi.3 smi_config.3 smi_module.3 smi_macro.3 smi_node.3 smi_type.3 \
        smi_render.3

.include <bsd.port.mk>
