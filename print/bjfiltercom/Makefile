# New ports collection makefile for: bjfiltercom
# Date created:		2001.02.10
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME?=	bjfiltercom
PORTVERSION?=	1.3
PORTREVISION=	5
CATEGORIES=	print linux
MASTER_SITES=	ftp://download.canon.jp/pub/driver/bj/linux/
DISTFILES=	${RPMFILE}
.if !defined(SLAVE_PORT)
DISTFILES+=	${DOC_DISTFILES}
.endif
EXTRACT_ONLY=	${RPMFILE}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Canon Bubble Jet Print Filter for Linux -- Common files

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
.if defined(SLAVE_PORT)
RUN_DEPENDS=	stsmon:${PORTSDIR}/print/bjfiltercom \
		pstops:${PORTSDIR}/print/psutils-${PAPERSIZE}
.else
USE_LINUX_APPS=	gtk jpeg libglade libxml tiff
BIN_FILES=	bjcmd  bjfilter  bjprn  lgmon  printui  stsmon
.endif

EXTRACT_CMD=	rpm2cpio.pl
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| ${CPIO} -id --quiet

PLIST_SUB+=	PORTVERSION=${PORTVERSION}${_SUF1}${_SUF2}
DIST_SUBDIR=	bjfilter
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo
ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
NO_MTREE=	yes
RPMREVISION=	1
.if defined(SLAVE_PORT)
PAPERSIZE?=	a4
.else
NO_BUILD=	yes
.endif
RPMFILE=	${PORTNAME}-${PORTVERSION}-${RPMREVISION}.i386.rpm
DOC_DIR=	${PREFIX}/share/doc/${PKGNAME}
HTML_DIR=	${DOC_DIR}/html
DOC_DISTFILES=	readme-${PORTVERSION}-${RPMREVISION}.tar.gz \
		instruction-${PORTVERSION}-${RPMREVISION}.tar.gz \
		faq-${PORTVERSION}-${RPMREVISION}.tar.gz
FILTER_NAME=	filter${PREFIX_PRTYPE}${PRTYPE}${SUFFIX_PRTYPE}
.if ! defined(PREFIX_PRTYPE)
PRMODEL=	F${PRTYPE}
.else
PRMODEL=	${PREFIX_PRTYPE:U}${PRTYPE}
.endif

do-build:
	${SED}	-e 's,%%PRMODEL%%,${PRMODEL},' \
		${FILESDIR}/filter > ${WRKDIR}/${FILTER_NAME}
	${SED}	-e 's,%%PRMODEL%%,${PRMODEL},' \
		-e 's,%%LINUXBASE%%,${LINUXBASE},g' \
		${FILESDIR}/filter_gui > ${WRKDIR}/${FILTER_NAME}_gui
	${SED}	-e 's,%%PORTNAME%%,${PORTNAME},g' \
		-e 's,%%FILTER_NAME%%,${FILTER_NAME},g' \
		-e 's,%%PRMODEL%%,${PRMODEL},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
			${FILESDIR}/setup > ${WRKDIR}/setup.freebsd

# XXX: this is missing "${BRANDELF} -t Linux <executables>"

do-install:
	${MKDIR} ${LINUXBASE}/usr/lib/bjlib
	${INSTALL_DATA} ${WRKDIR}/usr/lib/bjlib/* ${LINUXBASE}/usr/lib/bjlib
	${INSTALL_DATA} ${WRKDIR}/usr/lib/lib* ${LINUXBASE}/usr/lib
	-${LINUXBASE}/sbin/ldconfig
	${INSTALL_SCRIPT} ${WRKDIR}/usr/local/bin/* ${PREFIX}/bin
.if defined(SLAVE_PORT)
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${FILTER_NAME} \
		${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${FILTER_NAME}_gui \
		${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/setup.freebsd ${PREFIX}/libexec/${PORTNAME}/setup
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}/scripts
	${INSTALL_DATA} ${FILESDIR}/en.lc ${PREFIX}/libexec/${PORTNAME}/scripts
	${INSTALL_DATA} ${FILESDIR}/ja.lc ${PREFIX}/libexec/${PORTNAME}/scripts
.else
	${MKDIR} ${LINUXBASE}/usr/local/share/printui
	${MKDIR} ${LINUXBASE}/usr/local/share/locale/ja/LC_MESSAGES
	${INSTALL_DATA} ${WRKDIR}/usr/local/share/printui/* ${LINUXBASE}/usr/local/share/printui
#  The next file "i18n" is installed by ja-bjfilter*
	${RM} ${LINUXBASE}/usr/local/share/printui/i18n
	${INSTALL_DATA} ${WRKDIR}/usr/local/share/locale/ja/LC_MESSAGES/* \
		${LINUXBASE}/usr/local/share/locale/ja/LC_MESSAGES
	${MKDIR} ${LINUXBASE}/usr/local/share/stsmon/pixmaps
	${INSTALL_DATA} ${WRKDIR}/usr/local/share/stsmon/pixmaps/* \
		${LINUXBASE}/usr/local/share/stsmon/pixmaps
.for i in ${DOC_DISTFILES}
	${MKDIR} ${HTML_DIR}
	${TAR} -C ${HTML_DIR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${i}
	${INSTALL_DATA} ${FILESDIR}/license.txt.jp ${DOC_DIR}
.endfor
.endif

# a target for the maintainer
_MAKE_DESCR:
.if defined(SLAVE_PORT) && ${PORTNAME} != "bjfilter850"
.for file in pkg-comment pkg-descr
	${SED}	-e 's/F850/${PRMODEL}/g' \
		-e 's/850/${PREFIX_PRTYPE}${PRTYPE}${SUFFIX_PRTYPE}/g' \
		../bjfilter850/${file} > ${.CURDIR}/${file}
.endfor
.if defined(SUFFIX_PRTYPE) && ${SUFFIX_PRTYPE} == "ug"
	i=`cat ../bjfilter850/pkg-comment`; \
	echo $$i "(supported BCI-6 inks)" > ${.CURDIR}/pkg-comment
	echo "" >> ${.CURDIR}/pkg-descr
	echo "Notice: This is supported BCI-6 inks." >> ${.CURDIR}/pkg-descr
	echo "" >> ${.CURDIR}/pkg-descr
	echo "Notice: bjfilter850 and bjfilter850ug cannot be installed simultaneously." >> ${.CURDIR}/pkg-descr
.endif
.endif

.include <bsd.port.mk>
