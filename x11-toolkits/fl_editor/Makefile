# New ports collection makefile for: fl_editor
# Date created:		17 August 2001
# Whom:			Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	fl_editor
PORTVERSION=	0.4.5
PORTREVISION=	5
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://robertk.com/source/fl_editor/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text Editor Widgets for the Fast Light ToolKit

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-shared --with-fltk=${LOCALBASE}
USE_GMAKE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	INCSDIR="${INCSDIR:S,^${PREFIX}/,,}" \
		LIBSDIR="${LIBSDIR:S,^${PREFIX}/,,}"
REINPLACE_SUB=	PREFIX=${PREFIX}

INCSDIR=	${PREFIX}/include/FL
LIBSDIR=	${PREFIX}/lib

DOC_FILES=	documentation/*.html documentation/*.jpg
INC1_FILES=	Fl_Editor.H Fl_FancyEditor.H Fl_FancyMultiEditor.H \
		Fl_MultiEditor.H Fl_ProgressBox.H Fl_StatusPanel.H
INC2_FILES=	editengine.h editvars.h lists.h stringsup.h wstring.h
LIB_FILES=	libfleditor.so.1

post-patch: patch-inplace

patch-inplace:
	@${REINPLACE_CMD} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/Makefile.in

post-install: symlink-inc symlink-lib install-doc

symlink-inc:
.for file in ${INC1_FILES}
	@${LN} -fs ${file} ${INCSDIR}/${file:R}.${file:E:L}
.endfor
.for file in ${INC2_FILES}
	@${LN} -fs ${file} ${INCSDIR}/${file:R}.${file:E:U}
.endfor

symlink-lib:
.for file in ${LIB_FILES}
	@${LN} -fs ${file} ${LIBSDIR}/${file:R}
.endfor

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
