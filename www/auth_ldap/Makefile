# New ports collection makefile for:	auth_ldap
# Date created:				25 September 2001
# Whom:					nik
#
# $FreeBSD$
#

PORTNAME=	auth_ldap
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.rudedog.org/auth_ldap/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
LIB_DEPENDS=	lber.2:${PORTSDIR}/net/openldap2
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-llber"
CONFIGURE_ARGS= --with-sdk-headers=${LOCALBASE}/include \
		--with-sdk-libs=${LOCALBASE}/lib \
		--with-ldap-sdk=openldap \
		--with-apxs=${APXS}

USE_GMAKE=	yes

APXS?=		${LOCALBASE}/sbin/apxs

MAKE_ARGS+=	APXS=${APXS}

do-install:
	${APXS} -i -A -n ldap ${WRKSRC}/auth_ldap.so

.include <bsd.port.mk>
