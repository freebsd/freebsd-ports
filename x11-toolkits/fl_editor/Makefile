# New ports collection makefile for: fl_editor
# Date created:		17 August 2001
# Whom:			Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	fl_editor
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://robertk.com/source/fl_editor/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cyrille.lefevre@laposte.net
COMMENT=	Text Editor Widgets for the Fast Light ToolKit

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-shared --with-fltk=${PREFIX}
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
DOC_FILES=	documentation/*.html documentation/*.jpg
INC1_FILES=	Fl_Editor.H Fl_FancyEditor.H Fl_FancyMultiEditor.H \
		Fl_MultiEditor.H Fl_ProgressBox.H Fl_StatusPanel.H
INC2_FILES=	editengine.h editvars.h lists.h stringsup.h wstring.h
INC_SUBDIR=	include/FL
LIB_FILES=	libfleditor.so.1
LIB_SUBDIR=	lib

post-install: symlink-inc symlink-lib install-doc

symlink-inc:
.for file in ${INC1_FILES}
	@${LN} -fs ${file} ${PREFIX}/${INC_SUBDIR}/${file:R}.${file:E:L}
.endfor
.for file in ${INC2_FILES}
	@${LN} -fs ${file} ${PREFIX}/${INC_SUBDIR}/${file:R}.${file:E:U}
.endfor

symlink-lib:
.for file in ${LIB_FILES}
	@${LN} -fs ${file} ${PREFIX}/${LIB_SUBDIR}/${file:R}
.endfor

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
