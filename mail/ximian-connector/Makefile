# New ports collection makefile for:   ximian-connector
# Date created:        30 May 2004
# Whom:                kiesel
#
# $FreeBSD$
#

PORTNAME=	ximian
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}${PKGNAMESUFFIX}/2.0
PKGNAMESUFFIX=	-connector
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	kiesel@schlund.de
COMMENT=	Evolution plugin to connect to Microsoft Exchange servers

BUILD_DEPENDS=	evolution-${EVO_VERSION}:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	evolution-${EVO_VERSION}:${PORTSDIR}/mail/evolution

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_OPENLDAP=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -rpath ${X11BASE}/lib/evolution/${EVO_VERSION}"
CONFIGURE_ARGS=	--with-openldap=${LOCALBASE} \
		--with-static-ldap=no

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
EVO_VERSION=	2.0
PLIST_SUB=	VERSION="2.0" EVO_VERSION=${EVO_VERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000 && !defined(NO_KERBEROS) && \
	exists(/usr/lib/libkrb5.so)
CONFIGURE_ARGS+=	--with-krb5=/usr
.else
LIB_DEPENDS+=		krb5:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=	--with-krb5=${LOCALBASE}
.endif

.include <bsd.port.post.mk>
