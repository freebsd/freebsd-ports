# New ports collection makefile for:	ldapmodule
# Date created:		05.Jul 2000
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	ldapmodule
PORTVERSION=	1.10alpha3
CATEGORIES=	net
MASTER_SITES=	ftp://python-ldap.sourceforge.net/pub/python-ldap/
DISTNAME=	python-ldap-${PORTVERSION}-src

MAINTAINER=	dirk.meyer@dinoex.sub.org

LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap
BUILD_DEPENDS=	python1.5:${PORTSDIR}/lang/python15
RUN_DEPENDS=	python1.5:${PORTSDIR}/lang/python15

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
WRKSRC=		${WRKDIR}/${DISTNAME:S=-src==}

.include <bsd.port.mk>
