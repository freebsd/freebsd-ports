# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zfs
PORTVERSION=	1
PORTREVISION=	3
CATEGORIES=	sysutils python
MASTER_SITES=	# none
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	# none

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Python ZFS library

LICENSE=	CDDL

USE_PYTHON=	2
MAKEFILE=	${FILESDIR}/Makefile.lib
MAKE_ARGS+=	PYTHON_INCLUDEDIR="${PYTHON_INCLUDEDIR}" \
		PYTHON_LDFLAGS="-L${LOCALBASE}/lib -l${PYTHON_VERSION}"
NO_WRKSUBDIR=	yes
SRCDIR?=	/usr/src

SUB_FILES+=	compile.py
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PYFILES=	__init__.py \
		allow.py \
		dataset.py \
		groupspace.py\
		unallow.py \
		userspace.py \
		util.py

.if !exists(${SRCDIR}/cddl/contrib/opensolaris/lib/pyzfs) || \
 !exists(${SRCDIR}/cddl/contrib/opensolaris/cmd/pyzfs)
IGNORE=	requires ZFS v15 or higher sources with pyzfs (in ${SRCDIR})
.endif

.if !exists(${SRCDIR}/cddl/contrib/opensolaris/lib/libzfs_core/common/libzfs_core.h)
MAKEFILE=	${FILESDIR}/Makefile.lib.v28
.endif

.if exists(${SRCDIR}/cddl/contrib/opensolaris/lib/pyzfs/common/holds.py) && \
exists(${SRCDIR}/cddl/contrib/opensolaris/lib/pyzfs/common/table.py)
PYFILES+=	holds.py \
		table.py
PLIST_SUB+=	V28=""
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-util.py \
		${FILESDIR}/extra-patch-userspace.py
.else
PLIST_SUB+=	V28="@comment "
.endif

NO_STAGE=	yes
do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${SRCDIR}/cddl/contrib/opensolaris/cmd/pyzfs/pyzfs.py \
	${WRKSRC}/pyzfs.py
.for PYFILE in ${PYFILES}
	@${CP} ${SRCDIR}/cddl/contrib/opensolaris/lib/pyzfs/common/${PYFILE} \
	${WRKSRC}/${PYFILE}
.endfor

post-patch:
	
.for PYFILE in pyzfs.py ${PYFILES}
	@${REINPLACE_CMD} -e "s|#! /usr/bin/python.*|#! ${PYTHON_CMD}|g" \
		${WRKSRC}/${PYFILE}
.endfor

do-install:
	${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/zfs
.for PYFILE in ${PYFILES}
	${INSTALL_DATA} ${WRKSRC}/${PYFILE} \
		${PYTHONPREFIX_SITELIBDIR}/zfs
.endfor
	${INSTALL_DATA} ${WRKSRC}/ioctl.so ${PYTHONPREFIX_SITELIBDIR}/zfs
	@${PYTHON_CMD} ${WRKDIR}/compile.py ${PYTHONPREFIX_SITELIBDIR}/zfs
	@${PYTHON_CMD} -O ${WRKDIR}/compile.py ${PYTHONPREFIX_SITELIBDIR}/zfs
	${MKDIR} /usr/lib/zfs
	${INSTALL_SCRIPT} ${WRKSRC}/pyzfs.py /usr/lib/zfs
	@${PYTHON_CMD} ${WRKDIR}/compile.py /usr/lib/zfs
	@${PYTHON_CMD} -O ${WRKDIR}/compile.py /usr/lib/zfs

.include <bsd.port.mk>
