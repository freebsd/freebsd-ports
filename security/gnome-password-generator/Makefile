# New ports collection makefile for:	gnome-password-generator
# Date created:				2004-07-13
# Whom:					Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	gnome-password-generator
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	security gnome python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnome-password

MAINTAINER=	asa@gascom.ru
COMMENT=	GNOME 2 password generator

USE_GNOME=	pygnome2
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|prefix=/usr|prefix=${PREFIX}|g' -e 's|(prefix)/share|(prefix)/share/gnome|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' ${WRKSRC}/${PORTNAME}

.include <bsd.port.mk>
