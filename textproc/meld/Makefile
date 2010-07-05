# New ports collection makefile for:	meld
# Date created:				2003-04-13
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	meld
PORTVERSION=	1.3.2
CATEGORIES=	textproc devel python
MASTER_SITES=	GNOME

MAINTAINER=	c0rn@o2.pl
COMMENT=	GNOME 2 visual diff and merge tool

OPTIONS=	PYGNOMEDESKTOP "Code syntax hilighting (many dependencies)" off

USE_BZIP2=	yes
USE_GNOME=	pygnome2
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
MAKE_ARGS=	prefix=${PREFIX}
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
LICENSE=	GPLv2

post-patch:
.for file in Makefile
	@${REINPLACE_CMD} -e '/docdir_/d' ${WRKSRC}/${file}
.endfor
.for file in help/Makefile
	@${REINPLACE_CMD} -e '/^LANGUAGES/s|de||g' ${WRKSRC}/${file}
.endfor
.for file in help/C/Makefile help/es/Makefile help/fr/Makefile
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
