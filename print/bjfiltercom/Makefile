# New ports collection makefile for: bjfiltercom
# Date created:		2001.02.10
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME?=	bjfiltercom
PORTVERSION?=	1.1
PORTREVISION=	1
CATEGORIES=	print linux
MASTER_SITES=	ftp://www.canon-sales.co.jp/pub/driver/printer/BJ/linux/
DISTFILES=	${RPMFILE}
.if !defined(SLAVE_PORT)
DISTFILES+=	${DOC_DISTFILES}
.endif
EXTRACT_ONLY=	${RPMFILE}

MAINTAINER=	taoka@FreeBSD.org

BUILD_DEPENDS=  rpm2cpio:${PORTSDIR}/archivers/rpm2cpio
.if defined(SLAVE_PORT)
RUN_DEPENDS=	stsmon:${PORTSDIR}/print/bjfiltercom \
		pstops:${PORTSDIR}/print/psutils-${PAPERSIZE}
.else
RUN_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base \
		${LINUXBASE}/usr/lib/libxml.so.1:${PORTSDIR}/textproc/linux-libxml \
		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
		${LINUXBASE}/usr/lib/libtiff.so.3:${PORTSDIR}/graphics/linux-tiff \
		${LINUXBASE}/usr/lib/libglade.so.0:${PORTSDIR}/devel/linux-libglade \
		${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

BIN_FILES=	bjcmd  bjfilter  bjprn  lgmon  printui  stsmon
.endif

EXTRACT_CMD=	rpm2cpio
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| cpio -id --quiet

PLIST_SUB+=	PORTVERSION=${PORTVERSION}${_SUF1}${_SUF2}
DIST_SUBDIR=	bjfilter
PLIST=		${.CURDIR}/pkg-plist
COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr
MD5_FILE=	${.CURDIR}/distinfo
ONLY_FOR_ARCHS=	i386
NO_FILTER_SHLIBS=	yes
NO_MTREE=	yes
.if defined(SLAVE_PORT)
BIN_FILES=	bjf${PRTYPE}ps
FILTER=		${FILESDIR}/filter
PAPERSIZE?=	a4
RPMREVISION=	0
.else
NO_BUILD=	yes
RPMREVISION=	1
.endif
RPMFILE=	${PORTNAME}-${PORTVERSION}-${RPMREVISION}.i386.rpm
DOC_DIR=	${PREFIX}/share/doc/${PKGNAME}
HTML_DIR=	${DOC_DIR}/html
DOC_DISTFILES=	readme.tar.gz instruction.tar.gz faq.tar.gz

do-build:
	${SED}	-e 's,%%PRTYPE%%,${PRTYPE}${SUFIX_PRTYPE},' \
		${FILTER} > ${WRKDIR}/filter${PRTYPE}${SUFIX_PRTYPE}
	${SED}	-e 's,%%PRTYPE%%,${PRTYPE}${SUFIX_PRTYPE},' \
		${FILTER}_gui > ${WRKDIR}/filter${PRTYPE}${SUFIX_PRTYPE}_gui

do-install:
	${MKDIR} -p ${LINUXBASE}/usr/lib/bjlib
	${INSTALL_DATA} ${WRKDIR}/usr/lib/bjlib/* ${LINUXBASE}/usr/lib/bjlib
	${INSTALL_DATA} ${WRKDIR}/usr/lib/lib* ${LINUXBASE}/usr/lib
	${INSTALL_SCRIPT} ${WRKDIR}/usr/local/bin/* ${PREFIX}/bin
.if defined(SLAVE_PORT)
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/filter${PRTYPE}${SUFIX_PRTYPE} \
		${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/filter${PRTYPE}${SUFIX_PRTYPE}_gui \
		${PREFIX}/libexec/${PORTNAME}
.else
	${MKDIR} -p ${LINUXBASE}/usr/local/share/printui
	${MKDIR} -p ${LINUXBASE}/usr/local/share/locale/ja/LC_MESSAGES
	${INSTALL_DATA} ${WRKDIR}/usr/local/share/printui/* ${LINUXBASE}/usr/local/share/printui
	${INSTALL_DATA} ${WRKDIR}/usr/local/share/locale/ja/LC_MESSAGES/* \
		${LINUXBASE}/usr/local/share/locale/ja/LC_MESSAGES
	${MKDIR} ${HTML_DIR}
.for i in ${DOC_DISTFILES}
	${TAR} -C ${HTML_DIR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${i}
	${INSTALL_DATA} ${FILESDIR}/license.txt.jp ${DOC_DIR}
.endfor
.endif

# a target for the maintainer
_MAKE_COMMENT_DESCR:
.if defined(SLAVE_PORT) && ${PORTNAME} != "bjfilter850"
.for file in pkg-comment pkg-descr
	${SED}	-e 's/850/${PRTYPE}${SUFIX_PRTYPE}/g' ../bjfilter850/${file} \
		> ${.CURDIR}/${file}
.endfor
.if defined(SUFIX_PRTYPE) && ${SUFIX_PRTYPE} == "ug"
	i=`cat ../bjfilter850/pkg-comment`; \
	echo $$i "(supported BCI-6 inks)" > ${.CURDIR}/pkg-comment
	echo "" >> ${.CURDIR}/pkg-descr
	echo "Notice: This is supported BCI-6 inks." >> ${.CURDIR}/pkg-descr
	echo "" >> ${.CURDIR}/pkg-descr
	echo "Notice: bjfilter850 and bjfilter850ug cannot be installed simultaneously." >> ${.CURDIR}/pkg-descr
.endif
.endif

.include <bsd.port.mk>
