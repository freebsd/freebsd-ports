# New ports collection makefile for:	pessulus
# Date created:				14 March 2006
# Whom:					FreeBSD GNOME Team
#
# $FreeBSD$
#   $MCom: ports/sysutils/pessulus/Makefile,v 1.28 2010/04/02 04:24:02 avl Exp $
#

PORTNAME=	pessulus
PORTVERSION=	2.30.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A lockdown editor for GNOME

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack pygnome2 pygnomedesktop
WANT_GNOME=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog HACKING \
		MAINTAINERS NEWS README TODO

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
