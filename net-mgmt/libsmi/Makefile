# New ports collection makefile for:	libsmi
# Date created:			Tue Jan 27 2000
# Whom:				Marcin Cieslak <saper@system.pl>
#
# $FreeBSD$
#

PORTNAME=	libsmi
PORTVERSION=	0.4.2
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/libsmi/

MAINTAINER=	saper@system.pl
COMMENT=	A library to access SMI MIB information

INSTALLS_SHLIB=	yes
USE_GNOME=	pkgconfig gnomehack
USE_GMAKE=	yes
PIBDIR=		${PREFIX}/share/smi/pibs
MIBDIR=		${PREFIX}/share/smi/mibs
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-data-dir=${PREFIX}/share/smi \
		--with-pibdir=${PIBDIR} --with-mibdir=${MIBDIR}

MAN1=	smiquery.1 smilint.1 smidump.1 smistrip.1 smidiff.1 smicache.1
MAN3=	libsmi.3 smi_config.3 smi_module.3 smi_macro.3 smi_node.3 smi_type.3 \
	smi_render.3

.include <bsd.port.mk>
