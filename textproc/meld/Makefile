# New ports collection makefile for:	meld
# Date created:				2003-04-13
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	meld
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	textproc devel python
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME 2 visual diff and merge tool

USE_BZIP2=	yes
USE_GNOME=	pygnome2
INSTALLS_OMF=	yes
USE_PYTHON=	yes
NO_BUILD=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

MAKEFILE=	GNUmakefile

OPTIONS=	PYGNOMEDESKTOP "Code syntax hilighting (many dependencies)" off

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/INSTALL

	@${REINPLACE_CMD} \
		's|$$(sharedir)/applications|$$(sharedir)/gnome/applications|g ;\
		s|$$(sharedir)/application-registry|$$(sharedir)/gnome/application-registry|g ;\
		s|$$(sharedir)/pixmaps|$$(sharedir)/gnome/pixmaps|g' \
		${WRKSRC}/${MAKEFILE}

	@${FIND} ${WRKSRC}/help -type f -name ${MAKEFILE} -exec \
		${REINPLACE_CMD} \
		's|$$(prefix)/var/lib/scrollkeeper|/var/db/scrollkeeper|g ; \
		s|$$(sharedir)/omf/meld|$$(sharedir)/gnome/omf/meld|g' \
		"{}" \;

.include <bsd.port.pre.mk>
.if defined (WITH_PYGNOMEDESKTOP)
USE_GNOME+=	pygnomedesktop
.endif
.include <bsd.port.post.mk>
