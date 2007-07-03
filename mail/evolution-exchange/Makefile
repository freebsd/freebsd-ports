# New ports collection makefile for:	evolution-exchange
# Date created:				28 April, 2005
# Whom:					Adam Weinberger, based off kiesel's ximian-exchange port
#
# $FreeBSD$
#   $MCom: ports/mail/evolution-exchange/Makefile,v 1.83 2007/03/13 16:03:50 marcus Exp $
#

PORTNAME=	evolution-exchange
PORTVERSION=	2.10.3
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}${PKGNAMESUFFIX}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution plugin to connect to Microsoft Exchange servers

BUILD_DEPENDS=	evolution-${EVO_VERSION}:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	evolution-${EVO_VERSION}:${PORTSDIR}/mail/evolution

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BDB=	41
USE_OPENLDAP=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-openldap=${LOCALBASE} \
		--with-static-ldap=no \
		--disable-compile-warnings \
		--with-libdb=${LOCALBASE}

EVO_VERSION=	2.10
VERSION=	2.10
PLIST_SUB=	VERSION=${VERSION} EVO_VERSION=${EVO_VERSION} \
		EDS_VERSION="1.2" OLDDOCSDIR="share/doc/ximian-connector"

GCONF_SCHEMAS=	apps_exchange_addressbook-${VERSION}.schemas

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000 && !defined(NO_KERBEROS) && \
	exists(/usr/lib/libkrb5.so)
CONFIGURE_ARGS+=	--with-krb5=/usr
.else
LIB_DEPENDS+=		krb5:${PORTSDIR}/security/heimdal
.if defined(HEIMDAL_HOME)
CONFIGURE_ARGS+=	--with-krb5=${HEIMDAL_HOME} --with-krb5-includes=${HEIMDAL_HOME}/include
.else
CONFIGURE_ARGS+=	--with-krb5=${LOCALBASE}
.endif
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fPIC"
.endif

.if exists(${LOCALBASE}/include/mapi.h)
IGNORE=	does not build with ${LOCALBASE}/include/mapi.h exists in system, run pkg_info -W ${LOCALBASE}/include/mapi.h to find the offending port and uninstall it, then install ${PORTNAME} and reinstall port
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|EVOLUTION_API_VERSION=2.8|EVOLUTION_API_VERSION=2.10| ; \
	    	s|EDS_BASE_VERSION=1.8|EDS_BASE_VERSION=1.10| ; \
		s|-ldb|-l${BDB_LIB_NAME}|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
