# New ports collection makefile for:	pessulus
# Date created:				14 March 2006
# Whom:					FreeBSD GNOME Team
#
# $FreeBSD$
#   $MCom: ports/sysutils/pessulus/Makefile,v 1.3 2006/04/10 13:23:35 ahze Exp $
#

PORTNAME=	pessulus
PORTVERSION=	0.9.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.9
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A lockdown editor for GNOME

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack pygnome2
WANT_GNOME=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
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
