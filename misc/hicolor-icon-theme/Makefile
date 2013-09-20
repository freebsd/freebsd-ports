# Created by: marcus@FreeBSD.org
# $FreeBSD$
#   $MCom: ports/misc/hicolor-icon-theme/Makefile,v 1.9 2009/09/26 12:53:31 marcus Exp $

PORTNAME=	hicolor-icon-theme
PORTVERSION=	0.12
CATEGORIES=	misc gnome
MASTER_SITES=	http://icon-theme.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A high-color icon theme shell from the FreeDesktop project

GNU_CONFIGURE=	yes

ICON_DIR?=	share/icons/hicolor
ICON_FILES=	index.theme
SUB_FILES=	pkg-install
PKG_INSTALL=	${WRKDIR}/pkg-install
PLIST=	${WRKDIR}/pkg-plist

# Update the below from Makefile.in each release
ICON_SIZES=	16x16 22x22 24x24 32x32 36x36 48x48 64x64 72x72 96x96 \
		128x128 192x192 256x256 scalable
ICON_CONTEXTS=	actions animations apps categories devices emblems emotes \
		filesystems intl mimetypes places status stock
STOCK_SUBS=	chart code data form image io media navigation net object table text

SUB_LIST=	ICON_SIZES="${ICON_SIZES}" ICON_CONTEXTS="${ICON_CONTEXTS}" \
		STOCK_SUBS="${STOCK_SUBS}"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} -f ${PLIST}
.for file in ${ICON_FILES}
	@${ECHO_CMD} "${ICON_DIR}/${file}" >> ${PLIST}
.endfor
.for dir in ${ICON_SIZES}
. for ctxt in ${ICON_CONTEXTS}
	if [ "${ctxt}" = "stock" ] ; then \
	 for sub in ${STOCK_SUBS} ; do \
		${ECHO_CMD} "${ICON_DIR}/${dir}/${ctxt}/$${sub}/.keep_me" >> ${PLIST} ; \
	 done ; \
	fi
	${ECHO_CMD} "${ICON_DIR}/${dir}/${ctxt}/.keep_me" >> ${PLIST} ;
. endfor
.endfor
.for dir in ${ICON_SIZES}
. for ctxt in ${ICON_CONTEXTS}
	if [ "${ctxt}" = "stock" ] ; then \
	 for sub in ${STOCK_SUBS} ; do \
		${ECHO_CMD} "@dirrmtry ${ICON_DIR}/${dir}/${ctxt}/$${sub}" >> ${PLIST} ; \
	 done ; \
	fi
	${ECHO_CMD} "@dirrmtry ${ICON_DIR}/${dir}/${ctxt}" >> ${PLIST}
. endfor
	${ECHO_CMD} "@dirrmtry ${ICON_DIR}/${dir}" >> ${PLIST}
.endfor
	${ECHO_CMD} "@dirrmtry ${ICON_DIR}" >> ${PLIST}
	${ECHO_CMD} "@dirrmtry share/icons" >> ${PLIST}

post-install:
.for dir in ${ICON_SIZES}
. for ctxt in ${ICON_CONTEXTS}
	if [ "${ctxt}" = "stock" ] ; then \
	 for sub in ${STOCK_SUBS} ; do \
		${TOUCH} ${PREFIX}/${ICON_DIR}/${dir}/${ctxt}/$${sub}/.keep_me ; \
	 done ; \
	fi
	${TOUCH} ${PREFIX}/${ICON_DIR}/${dir}/${ctxt}/.keep_me
. endfor
.endfor

.include <bsd.port.post.mk>
