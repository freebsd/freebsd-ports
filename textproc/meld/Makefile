# New ports collection makefile for:	meld
# Date created:				2003-04-13
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	meld
PORTVERSION=	1.1.5.1
CATEGORIES=	textproc devel python
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME 2 visual diff and merge tool

OPTIONS=	PYGNOMEDESKTOP "Code syntax hilighting (many dependencies)" off

USE_BZIP2=	yes
USE_GNOME=	pygnome2
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ARGS=	prefix=${PREFIX}
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

post-patch:
	@${FIND} ${WRKSRC} -name "${MAKEFILE}" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(sharedir)/applications|$$(sharedir)/gnome/applications|g ; \
		 s|$$(sharedir)/application-registry|$$(sharedir)/gnome/application-registry|g ; \
		 s|$$(sharedir)/pixmaps|$$(sharedir)/gnome/pixmaps|g ; \
		 s|$$(localstatedir)/lib/scrollkeeper|/var/db/scrollkeeper|g ; \
		 s|$$(sharedir)/omf/meld|$$(sharedir)/gnome/omf/meld|g'

.include <bsd.port.pre.mk>

.if defined(WITH_PYGNOMEDESKTOP)
USE_GNOME+=	pygnomedesktop
.endif

.include <bsd.port.post.mk>
