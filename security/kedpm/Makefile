# Created by: Tim Welch <ports@thepentagon.org>
# $FreeBSD$

PORTNAME=	kedpm
PORTVERSION=	0.4.0
PORTREVISION=	8
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@thepentagon.org
COMMENT=	Simple application for managing personal data

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	YES

DESKTOP_ENTRIES="Ked Password Manager" \
		"Secure Password Management" \
		"${PREFIX}/share/${PORTNAME}/glade/logo.png" \
		"kedpm" \
		"" \
		true

NO_STAGE=	yes
.include <bsd.port.mk>
