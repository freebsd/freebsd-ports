# New ports collection makefile for:	auth_ldap
# Date created:				25 September 2001
# Whom:					nik
#
# $FreeBSD$
#

PORTNAME=	auth_ldap
PORTVERSION=	1.6.0
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.rudedog.org/auth_ldap/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache module to authenticate against an LDAP directory

LIB_DEPENDS=	lber.2:${PORTSDIR}/${LDAP_PORT}

USE_APACHE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-llber"
CONFIGURE_ARGS=	--with-sdk-headers=${LOCALBASE}/include \
		--with-sdk-libs=${LOCALBASE}/lib \
		--with-ldap-sdk=openldap \
		--with-apxs=${APXS}
USE_GMAKE=	yes

LDAP_PORT?=	net/openldap20-client

MAKE_ARGS+=	APXS=${APXS}

post-patch:
	${CP} -p ${WRKSRC}/auth_ldap.c ${WRKSRC}/mod_auth_ldap.c

do-install:
	${APXS} -i -a -n auth_ldap ${WRKSRC}/mod_auth_ldap.so

.include <bsd.port.mk>
