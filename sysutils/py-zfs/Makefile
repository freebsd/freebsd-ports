# New ports collection makefile for:	pyzfs
# Date created:				11 July 2010
# Whom:					Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zfs
PORTVERSION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	# none
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	# none

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Python ZFS library

USE_PYTHON=	2.4+
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

post-patch:
	@${MKDIR} ${WRKSRC}
	@${SED} -e "s|/usr/bin/python2.4|${PYTHON_CMD}|g" \
		${SRCDIR}/cddl/contrib/opensolaris/cmd/pyzfs/pyzfs.py \
		> ${WRKSRC}/pyzfs.py
.for PYFILE in ${PYFILES}
	@${SED} -e "s|/usr/bin/python2.4|${PYTHON_CMD}|g" \
		${SRCDIR}/cddl/contrib/opensolaris/lib/pyzfs/common/${PYFILE} \
		> ${WRKSRC}/${PYFILE}
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
