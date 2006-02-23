# New ports collection makefile for:	evolution-exchange
# Date created:				28 April, 2005
# Whom:					Adam Weinberger, based off kiesel's ximian-exchange port
#
# $FreeBSD$
#   $MCom: ports/mail/evolution-exchange/Makefile,v 1.39 2005/10/04 04:32:19 marcus Exp $
#

PORTNAME=	evolution-exchange
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}${PKGNAMESUFFIX}/2.4
DIST_SUBDIR=	gnome2

MAINTAINER=	kiesel@schlund.de
COMMENT=	Evolution plugin to connect to Microsoft Exchange servers

BUILD_DEPENDS=	evolution-${EVO_VERSION}:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	evolution-${EVO_VERSION}:${PORTSDIR}/mail/evolution

USE_BZIP2=	yes
USE_X_PREFIX=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OPENLDAP=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnometarget
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-openldap=${LOCALBASE} \
		--with-static-ldap=no \
		--disable-compile-warnings

EVO_VERSION=	2.4
PLIST_SUB=	VERSION="2.4" EVO_VERSION=${EVO_VERSION} EDS_VERSION="1.2" \
		OLDDOCSDIR="share/doc/ximian-connector"

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

.include <bsd.port.post.mk>
