# New ports collection makefile for:	meld
# Date created:				2003-04-13
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	meld
PORTVERSION=	1.5.4
CATEGORIES=	textproc devel python
MASTER_SITES=	GNOME

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	GNOME 2 visual diff and merge tool

LICENSE=	GPLv2

USE_XZ=		yes
USE_GNOME=	pygnome2
USE_PYTHON=	yes
USE_GMAKE=	yes
MAKE_ARGS=	prefix=${PREFIX}
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

OPTIONS=	PYGNOMEDESKTOP "Code syntax hilighting (many dependencies)" off

.if defined(WITHOUT_NLS)
EXTRA_PATCHES=	${FILESDIR}/extra-Makefile-without_nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

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

.include <bsd.port.options.mk>

.if defined(WITH_PYGNOMEDESKTOP)
USE_GNOME+=	pygnomedesktop
.endif

.include <bsd.port.mk>
