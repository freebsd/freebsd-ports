# New ports collection makefile for:	ghostscript
# Date created:		14 Jan 2002
# Whom:			Mita Yoshio <mita@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ghostscript
PORTVERSION=	6.52
CATEGORIES=	japanese print
MASTER_SITES=	# nonexistent
PKGNAMESUFFIX=	-gnu-cjk
DISTNAME=	# nonexistent
DISTFILES=	# empty

MAINTAINER=	mita@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/Resource/cid.sh:${PORTSDIR}/print/ghostscript-gnu-cjk\
		${X11BASE}/lib/X11/fonts/TrueType/kochi-mincho.ttf:${PORTSDIR}/japanese/kochi-ttfonts

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

GSLIB_DIR=	${PREFIX}/share/ghostscript/${PORTVERSION}/lib
PLIST_SUB=	GS_VERSION=${PORTVERSION}

do-install:
	${INSTALL_DATA} ${FILESDIR}/CIDFnmap.jp ${GSLIB_DIR}
	${MV} ${GSLIB_DIR}/CIDFnmap  ${GSLIB_DIR}/CIDFnmap.orig
	${GREP} -v -e "CIDFnmap.jp" ${GSLIB_DIR}/CIDFnmap.orig > \
		${GSLIB_DIR}/CIDFnmap
	${ECHO} '(CIDFnmap.jp) .runlibfile' >> ${GSLIB_DIR}/CIDFnmap

.include <bsd.port.mk>
