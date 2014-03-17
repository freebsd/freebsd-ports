# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	meld
PORTVERSION=	1.8.4
CATEGORIES=	textproc devel python
MASTER_SITES=	GNOME

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	GNOME 2 visual diff and merge tool

LICENSE=	GPLv2

USE_GNOME=	pygnome2
USES=		desktop-file-utils gmake shared-mime-info shebangfix tar:xz
python_OLD_CMD=	${SETENV} python
python_CMD=	${PYTHON_CMD}
SHEBANG_FILES=	bin/meld
USE_PYTHON=	2
MAKE_ARGS=	prefix=${PREFIX}
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

OPTIONS_DEFINE=		NLS PYGNOMEDESKTOP
OPTIONS_SUB=		yes

NLS_USES=		gettext

PYGNOMEDESKTOP_DESC=	Code syntax highlighting (many dependencies)
PYGNOMEDESKTOP_USE=	GNOME=pygnomedesktop

post-patch:
	@${REINPLACE_CMD} -e 's|^LANG :=|LANG_ :=|g ; s|$$(LANG)|$$(LANG_)|g ; \
		s|$$(localstatedir)/lib/scrollkeeper|/var/db/scrollkeeper|g' \
		${WRKSRC}/help/C/Makefile ${WRKSRC}/help/es/Makefile \
		${WRKSRC}/help/fr/Makefile

.include <bsd.port.mk>
