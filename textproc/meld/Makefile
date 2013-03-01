# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	meld
PORTVERSION=	1.7.1
CATEGORIES=	textproc devel python
MASTER_SITES=	GNOME

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	GNOME 2 visual diff and merge tool

LICENSE=	GPLv2

USE_XZ=		yes
USE_GNOME=	desktopfileutils pygnome2
USE_PYTHON=	-2.7
USE_GMAKE=	yes
MAKE_ARGS=	prefix=${PREFIX}
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

OPTIONS_DEFINE=		PYGNOMEDESKTOP
PYGNOMEDESKTOP_DESC=	Code syntax hilighting (many dependencies)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} '/docdir_/d' ${WRKSRC}/Makefile
.if !${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} '/po install/d' ${WRKSRC}/Makefile
.endif

.for file in help/C/Makefile help/es/Makefile help/fr/Makefile
	@${REINPLACE_CMD} -e \
		's|$$(localstatedir)/lib/scrollkeeper|/var/db/scrollkeeper|g ; \
		 s|^LANG :=|LANG_ :=|g ; \
		 s|$$(LANG)|$$(LANG_)|g' ${WRKSRC}/${file}
.endfor

.if ${PORT_OPTIONS:MPYGNOMEDESKTOP}
USE_GNOME+=	pygnomedesktop
.endif

.include <bsd.port.mk>
