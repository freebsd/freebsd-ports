# New ports collection makefile for:	parano
# Date created:		3 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	parano
PORTVERSION=	0.3.4
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	CENKES BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Gnome program to deal with hashfiles

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_GNOME=	gtk20
USE_GETTEXT=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's,#!.*python,#!${PYTHON_CMD},' ${WRKSRC}/src/parano.py

.include <bsd.port.mk>
