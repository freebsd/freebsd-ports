# New ports collection makefile for:	luma
# Date created:				19 November 2003
# Whom:					Alexander Novitsky
#
# $FreeBSD$
#

PORTNAME=	luma
PORTVERSION=	1.4
CATEGORIES=	sysutils net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-r1

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	A graphical tool for accessing and managing LDAP servers

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_ldap.so:${PORTSDIR}/net/py-ldap2 \
		${PYTHON_SITELIBDIR}/smbpasswd.so:${PORTSDIR}/net/py-smbpasswd \
		pyuic:${PORTSDIR}/x11-toolkits/py-qt

USE_BZIP2=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYSETUP=		install.py
PYDISTUTILS_BUILDARGS=		build
PYDISTUTILS_INSTALLARGS=	--prefix=${PREFIX}
USE_OPENLDAP=	yes

do-configure:

.include <bsd.port.mk>
