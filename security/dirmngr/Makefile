# New ports collection makefile for:	dirmngr
# Date created:		06 Feb 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	dirmngr
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG} \
		http://tigress.com/lofi/:lofi/
MASTER_SITE_SUBDIR=	alpha/aegypten
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		common.tar.gz:lofi

MAINTAINER=	michaelnottebrock@gmx.net
COMMENT=	A client for managing and downloading certificate revocation lists

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db2 \
		gcrypt.6:${PORTSDIR}/security/libgcrypt \
		ksba.7:${PORTSDIR}/security/libksba

USE_GETOPT_LONG=yes
USE_AUTOMAKE_VER=	15
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS+=--with-included-gettext=no

.include <bsd.port.pre.mk>

# We need OpenLDAP. Default on openldap20 but let people build with
# OpenLDAP 2.1.* if they want.

.if defined(WITH_LDAP21)
LIB_DEPENDS+=		ldap.2:${PORTSDIR}/net/openldap21
.else
LIB_DEPENDS+=		ldap.2:${PORTSDIR}/net/openldap20
.endif

post-extract:
	${MV} ${WRKDIR}/common ${WRKSRC}

pre-configure:
	${REINPLACE_CMD} -e "s@-lpthread@${PTHREAD_LIBS}@g" \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4 ${WRKSRC}/configure
	cd ${WRKSRC}; ./autogen.sh

.include <bsd.port.post.mk>
