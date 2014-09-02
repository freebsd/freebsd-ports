# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zfs
PORTVERSION=	1
PORTREVISION=	4
CATEGORIES=	sysutils python
MASTER_SITES=	# none
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python ZFS library

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/OPENSOLARIS.LICENSE

USES=		python:2
MAKEFILE=	${FILESDIR}/Makefile.lib
MAKE_ARGS+=	PYTHON_INCLUDEDIR="${PYTHON_INCLUDEDIR}" \
		PYTHON_LDFLAGS="-L${LOCALBASE}/lib -l${PYTHON_VERSION}"
NO_WRKSUBDIR=	yes

SUB_FILES+=	compile.py
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PYFILES=	__init__.py \
		allow.py \
		dataset.py \
		groupspace.py\
		unallow.py \
		userspace.py \
		util.py

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/cddl/contrib/opensolaris/lib/pyzfs) || \
 !exists(${SRC_BASE}/cddl/contrib/opensolaris/cmd/pyzfs)
IGNORE=	requires ZFS v15 or higher sources with pyzfs (in ${SRC_BASE})
.endif

.if !exists(${SRC_BASE}/cddl/contrib/opensolaris/lib/libzfs_core/common/libzfs_core.h)
MAKEFILE=	${FILESDIR}/Makefile.lib.v28
.endif

.if exists(${SRC_BASE}/cddl/contrib/opensolaris/lib/pyzfs/common/holds.py) && \
exists(${SRC_BASE}/cddl/contrib/opensolaris/lib/pyzfs/common/table.py)
PYFILES+=	holds.py \
		table.py
PLIST_SUB+=	V28=""
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-util.py \
		${FILESDIR}/extra-patch-userspace.py
.else
PLIST_SUB+=	V28="@comment "
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${SRC_BASE}/cddl/contrib/opensolaris/OPENSOLARIS.LICENSE \
	${WRKSRC}/OPENSOLARIS.LICENSE
	@${CP} ${SRC_BASE}/cddl/contrib/opensolaris/cmd/pyzfs/pyzfs.py \
	${WRKSRC}/pyzfs.py
.for PYFILE in ${PYFILES}
	@${CP} ${SRC_BASE}/cddl/contrib/opensolaris/lib/pyzfs/common/${PYFILE} \
	${WRKSRC}/${PYFILE}
.endfor

post-patch:

.for PYFILE in pyzfs.py ${PYFILES}
	@${REINPLACE_CMD} -e "s|#! /usr/bin/python.*|#! ${PYTHON_CMD}|g" \
		${WRKSRC}/${PYFILE}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zfs
.for PYFILE in ${PYFILES}
	${INSTALL_DATA} ${WRKSRC}/${PYFILE} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zfs
.endfor
	${INSTALL_DATA} ${WRKSRC}/ioctl.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zfs
	@${PYTHON_CMD} ${WRKDIR}/compile.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zfs
	@${PYTHON_CMD} -O ${WRKDIR}/compile.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zfs
	${MKDIR} ${STAGEDIR}/usr/lib/zfs
	${INSTALL_SCRIPT} ${WRKSRC}/pyzfs.py ${STAGEDIR}/usr/lib/zfs
	@${PYTHON_CMD} ${WRKDIR}/compile.py ${STAGEDIR}/usr/lib/zfs
	@${PYTHON_CMD} -O ${WRKDIR}/compile.py ${STAGEDIR}/usr/lib/zfs

.include <bsd.port.post.mk>
