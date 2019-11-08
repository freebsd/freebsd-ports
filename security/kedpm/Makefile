# Created by: Tim Welch <ports@thepentagon.org>
# $FreeBSD$

PORTNAME=	kedpm
PORTVERSION=	0.4.0
PORTREVISION=	8
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple application for managing personal data

LICENSE=	GPLv2+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR}

NO_ARCH=	yes

USES=		gnome python:2.7
USE_GNOME=	pygtk2
USE_PYTHON=	autoplist distutils

DESKTOP_ENTRIES="Ked Password Manager" "Secure Password Management" \
		"${DATADIR}/glade/logo.png" "kedpm" "" true

.include <bsd.port.mk>
