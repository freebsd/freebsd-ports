# New ports collection makefile for:	kedpm
# Date created:				25 April 2006
# Whom:					Tim Welch <ports@thepentagon.org>
#
# $FreeBSD$
#

PORTNAME=	kedpm
PORTVERSION=	0.4.0
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@thepentagon.org
COMMENT=	A simple application for managing personal data

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto

USE_GNOME=	pygtk2
USE_PYTHON=	2.1+
USE_PYDISTUTILS=	YES

DESKTOP_ENTRIES="Ked Password Manager" \
		"Secure Password Management" \
		"${LOCALBASE}/share/${PORTNAME}/glade/logo.png" \
		"kedpm" \
		"Application;System;" \
		true

.include <bsd.port.mk>
