# Created by: Adam Weinberger, based off kiesel's ximian-exchange port
# $FreeBSD$
#   $MCom: ports/trunk/mail/evolution-exchange3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	evolution-exchange
PORTVERSION=	3.4.4
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution plugin to connect to Microsoft Exchange servers

BUILD_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution

EVO_VER=	3.4.3
USE_XZ=	yes
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_BDB=	5
USE_OPENLDAP=	yes
USE_GNOME=	gnomeprefix intlhack ltasneededhack
CPPFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-openldap=${LOCALBASE} \
		--with-static-ldap=no \
		--with-libdb=${LOCALBASE}

VERSION=	3.4
PLIST_SUB=	VERSION=${VERSION}

GCONF_SCHEMAS=	apps_exchange_addressbook-${VERSION}.schemas

.include <bsd.port.pre.mk>

.if defined(HEIMDAL_HOME) || defined(WITH_HEIMDAL) || defined(NO_KERBEROS)
HEIMDAL_HOME?=		${LOCALBASE}
LIB_DEPENDS+=           krb5:${PORTSDIR}/security/heimdal
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
		-e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} '/g_thread_init/d' \
		${WRKSRC}/tools/ximian-connector-setup.c

.include <bsd.port.post.mk>
