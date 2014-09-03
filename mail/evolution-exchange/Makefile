# Created by: Adam Weinberger, based off kiesel's ximian-exchange port
# $FreeBSD$
#   $MCom: ports/mail/evolution-exchange/Makefile,v 1.172 2012/09/20 23:06:27 kwm Exp $

PORTNAME=	evolution-exchange
PORTVERSION=	2.32.1
PORTREVISION=	8
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution plugin to connect to Microsoft Exchange servers

EVO_PC_FILE=	${LOCALBASE}/libdata/pkgconfig/evolution-mail.pc
BUILD_DEPENDS=	${EVO_PC_FILE}:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	${EVO_PC_FILE}:${PORTSDIR}/mail/evolution

CONFLICTS=	evolution-exchange-3.[0-9]*

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_BDB=	41+
USE_OPENLDAP=	yes
USE_GNOME=	gnomeprefix intlhack
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-openldap=${LOCALBASE} \
		--with-static-ldap=no \
		--with-libdb=${LOCALBASE}

EVO_VERSION=	2.32
VERSION=	2.32
PLIST_SUB=	VERSION=${VERSION} EVO_VERSION=${EVO_VERSION} \
		EDS_VERSION="1.2"

GCONF_SCHEMAS=	apps_exchange_addressbook-${VERSION}.schemas

.include <bsd.port.pre.mk>

.if defined(HEIMDAL_HOME) || defined(WITH_HEIMDAL) || defined(NO_KERBEROS)
HEIMDAL_HOME?=		${LOCALBASE}
LIB_DEPENDS+=           libkrb5.so:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=        --with-krb5=${HEIMDAL_HOME} \
			--with-krb5-includes=${HEIMDAL_HOME}/include
KRB5_LIB=		`${HEIMDAL_HOME}/bin/krb5-config gssapi --libs`
.elif !defined(NO_KERBEROS)
CONFIGURE_ARGS+=        --with-krb5=/usr
KRB5_LIB=		`/usr/bin/krb5-config gssapi --libs`
.endif

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.if exists(${LOCALBASE}/include/mapi.h)
IGNORE=	build fails when ${LOCALBASE}/include/mapi.h exists in system, run pkg which ${LOCALBASE}/include/mapi.h to find the offending port and uninstall it, then install ${PORTNAME} and reinstall the port that installed mapi.h
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g' \
		-e 's|-lkrb5 -lcrypto -lasn1 -lcom_err -lroken -lgssapi|${KRB5_LIB}|g' \
		-e 's|-DGTK_DISABLE_DEPRECATED||g' \
		-e 's|-DG_DISABLE_DEPRECATED||g' \
		-e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} '/g_thread_init/d' \
		${WRKSRC}/tools/ximian-connector-setup.c

.include <bsd.port.post.mk>
