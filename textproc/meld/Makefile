# New ports collection makefile for:	meld
# Date created:				2003-04-13
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	meld
PORTVERSION=	0.9.4.1
PORTREVISION=	2
CATEGORIES=	textproc devel python
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.9

MAINTAINER=	rui@ruilopes.com
COMMENT=	GNOME 2 visual diff and merge tool

USE_BZIP2=	yes
USE_GNOME=	pygnome2
USE_PYTHON=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

MAKEFILE=	GNUmakefile

post-patch:
	@${REINPLACE_CMD} -E 's,(prefix := )(.*),\1${PREFIX},; \
		s,(libdir := )(.*),\1${PREFIX}/share,' ${WRKSRC}/GNUmakefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/meld.desktop ${PREFIX}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/manual/stylesheet.css ${DOCSDIR}

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX}|${SED} -E 's,.*share/nls/.+$$,,g;s,share/doc/meld,%%DOCSDIR%%,;s,^@dirrm share/(gnome|pixmaps|application|locale).*,,'|${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.mk>
