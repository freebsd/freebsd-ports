# New ports collection makefile for:	libfwbuilder
# Date Created:				27 May 2002
# Whom:					Sergey Lyubka <devnull@asitatech.ie>
#
# $FreeBSD$

PORTNAME=	libfwbuilder
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fwbuilder

MAINTAINER=	vadim@fwbuilder.org
COMMENT=	Firewall Builder API

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf \
		aclocal:${PORTSDIR}/devel/automake
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt \
		netsnmp.6:${PORTSDIR}/net/net-snmp \
		crypto.3:${PORTSDIR}/security/openssl

CONFIGURE_SCRIPT= autogen.sh
#CONFIGURE_ARGS=
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
