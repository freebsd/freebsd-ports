# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	meld
PORTVERSION=	1.8.3
CATEGORIES=	textproc devel python
MASTER_SITES=	GNOME

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	GNOME 2 visual diff and merge tool

LICENSE=	GPLv2

USE_XZ=		yes
USE_GNOME=	pygnome2
USES=		desktop-file-utils gmake shared-mime-info
USE_PYTHON=	2
MAKE_ARGS=	prefix=${PREFIX}
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

OPTIONS_DEFINE=		NLS PYGNOMEDESKTOP
OPTIONS_SUB=		yes

NLS_USES=		gettext

PYGNOMEDESKTOP_DESC=	Code syntax highlighting (many dependencies)
PYGNOMEDESKTOP_USE=	gnome=pygnomedesktop

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} '/docdir_/d' ${WRKSRC}/Makefile
.if !${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} '/po install/d' ${WRKSRC}/Makefile
.endif

.for file in help/C/Makefile help/es/Makefile help/fr/Makefile
	@${REINPLACE_CMD} -e \
		's|$$(localstatedir)/lib/scrollkeeper|/var/db/scrollkeeper|g ; \
		 s|^LANG :=|LANG_ :=|g ; \
		 s|$$(LANG)|$$(LANG_)|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
