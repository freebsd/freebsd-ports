# New ports collection makefile for:	libfwbuilder
# Date Created:				27 May 2002
# Whom:					Sergey Lyubka <devnull@asitatech.ie>
#
# $FreeBSD$

PORTNAME=	libfwbuilder
PORTVERSION=	1.0.0
PORTREVISION=   RC2
CATEGORIES=	security
MASTER_SITES=	ftp://downloads.fwbuilder.org/pub/fwbuilder/nightly_builds/current/ \
		${MASTER_SITE_SOURCEFORGE}/fwbuilder/

MAINTAINER=	devnull@uptsoft.com
COMMENT=	Firewall Builder API

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.1:${PORTSDIR}/textproc/libxslt \
		crypto.3:${PORTSDIR}/security/openssl \
		netsnmp.5:${PORTSDIR}/net/net-snmp \
		isc.1:${PORTSDIR}/net/bind9

CONFIGURE_SCRIPT= autogen.sh
CONFIGURE_ARGS=
USE_AUTOCONF=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_GTK=	no
INSTALLS_SHLIB=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

post-patch:
	@${ECHO_CMD} "===! Running aclocal"
	@(cd ${WRKSRC}; aclocal)

.include <bsd.port.mk>
