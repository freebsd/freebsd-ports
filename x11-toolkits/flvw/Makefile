# New ports collection makefile for:   	flvw
# Date created:				17 August 2001
# Whom:                			Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	flvw
PORTVERSION=	20000224
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	cyrille.lefevre@laposte.net
COMMENT=	Virtual Widgets for the Fast Light ToolKit

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

WRKSRC=		${WRKDIR}/${PORTNAME}/1.0
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	DIRS=src

DOC_FILES=	documentation/html/*.html
DOC_SUBDIR=	share/doc/${PKGBASE}
INC_FILES=	Flv_CStyle.H Flv_Data_Source.H Flv_List.H Flv_Style.H \
		Flv_Table.H Flve_Check_Button.H Flve_Combo.H Flve_Input.H
INC_SUBDIR=	include/FL

INSTALLS_SHLIB=	yes

post-patch:
	${REINPLACE_CMD} 's/^#define fl_inactive inactive//' \
		${WRKSRC}/FL/Flv_List.H
	${REINPLACE_CMD} 's/\(friend\) \(Flv_Style_List\)/\1 class \2/' \
		${WRKSRC}/FL/Flv_Style.H

post-install: symlink-inc install-doc

symlink-inc:
.for file in ${INC_FILES}
	@${LN} -fs ${file} ${PREFIX}/${INC_SUBDIR}/${file:R}.${file:E:L}
.endfor

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOC_SUBDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/${DOC_SUBDIR}
.endfor
.endif

.include <bsd.port.mk>
