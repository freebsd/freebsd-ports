# New ports collection makefile for:	libfwbuilder
# Date Created:				27 May 2002
# Whom:					Sergey Lyubka <devnull@asitatech.ie>
#
# $FreeBSD$

PORTNAME=	libfwbuilder
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fwbuilder

MAINTAINER=	vadim@fwbuilder.org
COMMENT=	Firewall Builder API

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt \
		netsnmp.6:${PORTSDIR}/net/net-snmp \
		crypto.3:${PORTSDIR}/security/openssl

USE_GNOME=	glib12

USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR}
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
