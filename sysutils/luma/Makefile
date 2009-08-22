# New ports collection makefile for:	luma
# Date created:				19 November 2003
# Whom:					Alexander Novitsky
#
# $FreeBSD$
#

PORTNAME=	luma
PORTVERSION=	2.3
PORTREVISION=	3
CATEGORIES=	sysutils net-mgmt
MASTER_SITES=	SF
# MASTER_SITES=	http://home.tu-clausthal.de/~ifwd/luma/

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	A graphical tool for accessing and managing LDAP servers

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap2>=2.3.1:${PORTSDIR}/net/py-ldap2 \
		${PYTHON_SITELIBDIR}/smbpasswd.so:${PORTSDIR}/net/py-smbpasswd \
		pyuic:${PORTSDIR}/x11-toolkits/py-qt

USE_BZIP2=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYSETUP=		install.py
PYDISTUTILS_BUILDARGS=		build
PYDISTUTILS_INSTALLARGS=	--prefix=${PREFIX}
PYDISTUTILS_NOEGGINFO=		yes
USE_OPENLDAP=	yes

MAN1=		luma.1

post-extract:
	@${MV} ${WRKSRC}/share/man ${WRKSRC}/

do-configure:

.include <bsd.port.mk>
