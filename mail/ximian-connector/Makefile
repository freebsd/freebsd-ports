# New ports collection makefile for:   ximian-connector
# Date created:        30 May 2004
# Whom:                kiesel
#
# $FreeBSD$
#

PORTNAME=	ximian
PORTVERSION=	1.4.7.1
CATEGORIES=	mail gnome
MASTER_SITES=	http://ftp.ximian.com/pub/source/evolution/
PKGNAMESUFFIX=	-connector
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	kiesel@schlund.de
COMMENT=	Evolution plugin to connect to Microsoft Exchange servers

BUILD_DEPENDS=	evolution-${EVO_VERSION}:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	evolution-${EVO_VERSION}:${PORTSDIR}/mail/evolution

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WANT_OPENLDAP_VER=	21
WANT_OPENLDAP_SASL=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-openldap=${LOCALBASE} \
		--with-static-ldap=no

EVO_VERSION=	1.4
PLIST_SUB=	VERSION="1.4" EVO_VERSION=${EVO_VERSION}

.include <bsd.port.mk>
