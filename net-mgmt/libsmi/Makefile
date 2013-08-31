# Created by: Marcin Cieslak <saper@system.pl>
# $FreeBSD$

PORTNAME=	libsmi
PORTVERSION=	0.4.8
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/libsmi/ \
		LOCAL/bms

MAINTAINER=	saper@saper.info
COMMENT=	A library to access SMI MIB information

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig
PIBDIR=		${PREFIX}/share/smi/pibs
MIBDIR=		${PREFIX}/share/smi/mibs
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-data-dir=${PREFIX}/share/smi \
		--with-pibdir=${PIBDIR} --with-mibdir=${MIBDIR}

MAN1=	smiquery.1 smilint.1 smidump.1 smistrip.1 smidiff.1 smicache.1 \
	smixlate.1
MAN3=	libsmi.3 smi_attribute.3 smi_class.3 smi_config.3 smi_event.3 \
	smi_identity.3 smi_module.3 smi_macro.3 smi_node.3 smi_type.3 \
	smi_render.3 smi_util.3

.include <bsd.port.mk>
