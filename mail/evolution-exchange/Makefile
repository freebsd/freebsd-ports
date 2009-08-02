# New ports collection makefile for:	evolution-exchange
# Date created:				28 April, 2005
# Whom:					Adam Weinberger, based off kiesel's ximian-exchange port
#
# $FreeBSD$
#   $MCom: ports-stable/mail/evolution-exchange/Makefile,v 1.3 2009/04/16 01:14:40 kwm Exp $
#

PORTNAME=	evolution-exchange
PORTVERSION=	2.26.3
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution plugin to connect to Microsoft Exchange servers

BUILD_DEPENDS=	evolution:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	evolution:${PORTSDIR}/mail/evolution

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_BDB=	41
USE_OPENLDAP=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack ltasneededhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-openldap=${LOCALBASE} \
		--with-static-ldap=no \
		--disable-compile-warnings \
		--with-libdb=${LOCALBASE}

EVO_VERSION=	2.26
VERSION=	2.26
PLIST_SUB=	VERSION=${VERSION} EVO_VERSION=${EVO_VERSION} \
		EDS_VERSION="1.2"

GCONF_SCHEMAS=	apps_exchange_addressbook-${VERSION}.schemas

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fPIC"
.endif

.if exists(${LOCALBASE}/include/mapi.h)
IGNORE=	build fails when ${LOCALBASE}/include/mapi.h exists in system, run pkg_info -W ${LOCALBASE}/include/mapi.h to find the offending port and uninstall it, then install ${PORTNAME} and reinstall the port that installed mapi.h
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
