# New ports collection makefile for:	luma
# Date created:				19 November 2003
# Whom:					Alexander Novitsky
#
# $FreeBSD$
#

PORTNAME=	luma
PORTVERSION=	1.0.b2
CATEGORIES=	sysutils net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-1.0beta2

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	A graphical tool for accessing and managing LDAP servers

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_ldap.so:${PORTSDIR}/net/py-ldap2 \
		pyuic:${PORTSDIR}/x11-toolkits/py-qt \
		${PYTHON_SITELIBDIR}/mx/TextTools/__init__.py:${PORTSDIR}/lang/py-mx-base

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_OPENLDAP=	yes
WANTS_OPENLDAP_VER=	2.1
NO_BUILD=	yes

INSTALLCMD=	install.py
INSTALLARGS=	--prefix=${LOCALBASE}

do-install:
	@(cd ${INSTALL_WRKSRC}; ${PYTHON_CMD} ${INSTALLCMD} ${INSTALLARGS})

.include <bsd.port.mk>
