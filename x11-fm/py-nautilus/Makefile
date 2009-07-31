# New ports collection makefile for:	py-nautilus
# Date created:				31 May, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-fm/py-nautilus/Makefile,v 1.11 2009/04/07 17:54:12 marcus Exp $
#

PORTNAME=	nautilus
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	x11-fm gnome python
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/nautilus-python/${PORTVERSION:R}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	nautilus-python-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python nautilus bindings

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack pygnome2 eel2 nautilus2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `pkg-config --cflags gnome-vfs-2.0`" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		LIBS="`pkg-config --libs gnome-vfs-2.0`"

DOCSDIR=	${PREFIX}/share/doc/nautilus-python

post-patch:
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/doc/|(prefix)/share/doc/|g' \
		${WRKSRC}/examples/Makefile.in

.include <bsd.port.mk>
