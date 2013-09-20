# Created by: Anders F Bjorklund <afb@rpm5.org>
# $FreeBSD$

PORTNAME=	createrepo
PORTVERSION=	0.9.8
CATEGORIES=	sysutils
MASTER_SITES=	http://createrepo.baseurl.org/download/

MAINTAINER=	afb@rpm5.org
COMMENT=	Creates a common metadata repository

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/sqlitecachec.py:${PORTSDIR}/devel/py-yum-metadata-parser \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/urlgrabber/__init__.py:${PORTSDIR}/www/py-urlgrabber \
		${PYTHON_SITELIBDIR}/yum/__init__.py:${PORTSDIR}/sysutils/yum

USE_PYTHON=	yes
USE_GMAKE=	yes

BUILD_DEPENDS+=	ginstall:${PORTSDIR}/sysutils/coreutils
GINSTALL=	ginstall

MAKE_ARGS=	MAKE=${GMAKE} INSTALL="${GINSTALL} -p -v" PYTHON=${PYTHON_CMD} \
		prefix=${PREFIX} mandir=${MANPREFIX}/man sysconfdir=${PREFIX}/etc

MAN1=		mergerepo.1 modifyrepo.1
MAN8=		createrepo.8

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|/usr/share/createrepo|${DATADIR}|g' \
		${WRKSRC}/bin/mergerepo \
		${WRKSRC}/bin/modifyrepo \
		${WRKSRC}/bin/createrepo
	${REINPLACE_CMD} -e 's|#!/usr/bin/python -t|#!${PYTHON_CMD}|' \
		${WRKSRC}/genpkgmetadata.py \
		${WRKSRC}/dmd.py \
		${WRKSRC}/mergerepo.py \
		${WRKSRC}/createrepo/deltarpms.py \
		${WRKSRC}/createrepo/utils.py \
		${WRKSRC}/createrepo/yumbased.py \
		${WRKSRC}/createrepo/readMetadata.py \
		${WRKSRC}/createrepo/merge.py
	${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|' -e 's|$$(datadir)/$$(PKGNAME)|${DATADIR}|' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/^PYSYSDIR/s|:= \(.*\)|= ${PREFIX}|' \
	    ${WRKSRC}/createrepo/Makefile

.include <bsd.port.mk>
