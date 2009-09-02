# New ports collection makefile for:	meld
# Date created:				2003-04-13
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	meld
PORTVERSION=	1.3.1
CATEGORIES=	textproc devel python
MASTER_SITES=	GNOME

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
.for file in GNUmakefile
	@${REINPLACE_CMD} -e '/docdir_/d' ${WRKSRC}/${file}
.endfor 
.for file in help/GNUmakefile
	@${REINPLACE_CMD} -e '/^LANGUAGES/s|de||g' ${WRKSRC}/${file}
.endfor 
.for file in help/C/GNUmakefile help/es/GNUmakefile help/fr/GNUmakefile
	@${REINPLACE_CMD} -e \
		's|$$(localstatedir)/lib/scrollkeeper|/var/db/scrollkeeper|g ; \
		 s|^LANG :=|LANG_ :=|g ; \
		 s|$$(LANG)|$$(LANG_)|g' ${WRKSRC}/${file}
.endfor 

.include <bsd.port.pre.mk>

.if defined(WITH_PYGNOMEDESKTOP)
USE_GNOME+=	pygnomedesktop
.endif

.include <bsd.port.post.mk>
