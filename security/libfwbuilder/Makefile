# New ports collection makefile for:	libfwbuilder
# Date Created:				27 May 2002
# Whom:					Sergey Lyubka <devnull@asitatech.ie>
#
# $FreeBSD$

PORTNAME=	libfwbuilder
PORTVERSION=	1.0.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fwbuilder

MAINTAINER=	vadim@fwbuilder.org
COMMENT=	Firewall Builder API

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt \
		netsnmp.6:${PORTSDIR}/net/net-snmp \
		crypto.3:${PORTSDIR}/security/openssl

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
WANT_AUTOMAKE_VER=	15
CONFIGURE_SCRIPT=	autogen.sh
CONFIGURE_ARGS=		--with-docdir=${DOCSDIR}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

post-patch:
	@${ECHO_MSG} "===! Running aclocal"
	cd ${WRKSRC} && aclocal

.include <bsd.port.mk>
