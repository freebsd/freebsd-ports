# New ports collection makefile for:	ldapmodule
# Date created:		05.Jul 2000
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	ldapmodule
PORTVERSION=	1.10alpha3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://python-ldap.sourceforge.net/pub/python-ldap/
DISTNAME=	python-ldap-${PORTVERSION}-src

MAINTAINER=	dirk.meyer@dinoex.sub.org

LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap
BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
WRKSRC=		${WRKDIR}/${DISTNAME:S=-src==}

.include <bsd.port.mk>
