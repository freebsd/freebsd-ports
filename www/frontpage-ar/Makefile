# New ports collection makefile for:	FrontPage Arabic Web Administration
# Date created:		Sat Oct 25 16:30:00 CDT 2001
# Whom:			hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	frontpage
PORTVERSION=	5.0.2.4803
CATEGORIES?=	www
MASTER_SITES=	http://download.microsoft.com/download/FrontPage2002/Utility/2002/UNIX/EN-US/ \
		ftp://ftp.microsoft.com/products/frontpage/FPSE02LangFiles/
PKGNAMEPREFIX?=	ar-
DISTFILES=
EXTRACT_ONLY=

MAINTAINER?=	swhetzel@gmail.com
COMMENT?=	Microsoft Frontpage Arabic Web Administration

RUN_DEPENDS=	${FPSETPERM}:${PORTSDIR}/www/frontpage

FP_LANG?=	ara
FP_LANGUAGE?=	Arabic
FP_LCID?=	1025

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/frontpage/Makefile.fp.common"

.for _FP_LANG in ${FP_LANG}
DISTFILES+=	fp${FP_VER:S/.//}_${_FP_LANG}.tar.Z
.endfor

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

FPSETPERM=	${PREFIX}/${FP_DIR}/set_default_perms.sh

.ifndef NO_FP_LCID_SUB
PLIST_SUB+=	FP_LCID=${FP_LCID}
.endif

do-install:
	@${ECHO_MSG} "===> Untaring FrontPage ${FP_LANGUAGE} Language Extensions to ${PREFIX}"
.for DISTFILE in ${DISTFILES}
	@(cd ${PREFIX} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE} ${EXTRACT_AFTER_ARGS})
.endfor
.for _FP_LCID in ${FP_LCID}
	@${REINPLACE_CMD} -e 's:IMAGESDIR:../images/:g' \
		${PREFIX}/${FP_DIR}/admin/${_FP_LCID}/webadmin.css
	@if [ -f ${PREFIX}/${FP_DIR}/admin/${_FP_LCID}/webadmin.css.bak ] ; then \
		${RM} ${PREFIX}/${FP_DIR}/admin/${_FP_LCID}/webadmin.css.bak ; \
	fi
	@if [ ! -f ${PREFIX}/${FP_DIR}/help/${_FP_LCID}/wsgindex.htm ]; then \
		${CP}	${PREFIX}/${FP_DIR}/help/${_FP_LCID}/wsgIndex.htm \
			${PREFIX}/${FP_DIR}/help/${_FP_LCID}/wsgindex.htm ; \
	fi
	@if [ ! -f ${PREFIX}/${FP_DIR}/help/${_FP_LCID}/wsgIndex.htm ]; then \
		${CP}	${PREFIX}/${FP_DIR}/help/${_FP_LCID}/wsgindex.htm \
			${PREFIX}/${FP_DIR}/help/${_FP_LCID}/wsgIndex.htm ; \
	fi
.endfor
	@${FPSETPERM}

.include <bsd.port.post.mk>
