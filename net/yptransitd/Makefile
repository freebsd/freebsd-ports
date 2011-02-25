# New ports collection makefile for:	yptransitd
# Date created:				26 September 2002
# Whom:					Michael Joyner <mjoyner@hq.dyns.cx>
#
# $FreeBSD$
#

PORTNAME=	yptransitd
PORTVERSION=	0.5
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A replacement for nss_ldap

USE_OPENLDAP=	yes
USE_BISON=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ldap-prefix=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -E 's,^([[:blank:]]+)\([^\)]+\) ,\1,' \
		${WRKSRC}/src/modules.c
	@${REINPLACE_CMD} -e 's,(void \*) ,,g' \
		${WRKSRC}/src/modules/ldap/cache.c

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
