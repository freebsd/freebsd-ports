# New ports collection makefile for: bjfiltercom
# Date created:		2001.02.10
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME?=	bjfiltercom
PORTVERSION?=	1.0
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
RUN_DEPENDS=	/compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_base \
		/compat/linux/usr/lib/libxml.so.1:${PORTSDIR}/textproc/linux-libxml \
		/compat/linux/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
		/compat/linux/usr/lib/libtiff.so.3:${PORTSDIR}/graphics/linux-tiff \
		/compat/linux/usr/lib/libglade.so.0:${PORTSDIR}/devel/linux-libglade
BIN_FILES=	bjprn stsmon printui lgmon bjfilter
.endif

EXTRACT_CMD=	rpm2cpio
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| cpio -id --quiet

PLIST_SUB=	PORTVERSION=${PORTVERSION}
DIST_SUBDIR=	bjfilter
PLIST=		${.CURDIR}/pkg-plist
COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr
MD5_FILE=	${.CURDIR}/distinfo
ONLY_FOR_ARCHS=	i386
NO_FILTER_SHLIBS=	yes
NO_MTREE=	yes
RPMFILE=	${PORTNAME}-${PORTVERSION}-0.i386.rpm
.if defined(SLAVE_PORT)
BIN_FILES=	bjpsprn
FILTER=		${FILESDIR}/filter
PAPERSIZE?=	a4
.else
NO_BUILD=	yes
.endif
DOC_DIR=	${PREFIX}/share/doc/bjfiltercom-${PORTVERSION}
HTML_DIR=	${DOC_DIR}/html
DOC_DISTFILES=	readme.tar.gz instruction.tar.gz faq.tar.gz

do-build:
	${SED}	-e 's,%%PRTYPE%%,${PRTYPE},' \
		${FILTER} > ${WRKDIR}/filter${PRTYPE}

do-install:
	cd ${WRKDIR}; \
	${TAR} cf - usr | ${TAR} xf - -C /compat/linux
.for i in ${BIN_FILES}
	${MV} -f /compat/linux/usr/local/bin/$i ${PREFIX}/bin
.endfor
.if defined(SLAVE_PORT)
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/filter${PRTYPE} \
		${PREFIX}/libexec/${PORTNAME}
.else
	${MKDIR} ${HTML_DIR}
.for i in ${DOC_DISTFILES}
	${TAR} -C ${HTML_DIR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${i}
	${INSTALL_DATA} ${FILESDIR}/license.txt.jp ${DOC_DIR}
.endfor
.endif

# a target for the maintainer
_MAKE_COMMENT_DESCR:
.if defined(SLAVE_PORT) && ${PRTYPE} != "850"
.for file in pkg-comment pkg-descr
	${SED}	-e 's/850/${PRTYPE}/g' ../bjfilter850/${file} \
		> ${.CURDIR}/${file}
.endfor
.endif

.include <bsd.port.mk>
