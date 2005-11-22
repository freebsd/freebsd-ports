# New ports collection makefile for:	thttpd-st
# Date created:		2005-09-21
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PKGNAMESUFFIX=-st

PATCH_SITES=	file://${.CURDIR}/files/
PATCHFILES=	st-patch-fdwatch.c st-patch-thttpd.c st-patch-Makefile.in

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	Tiny/turbo/throttling HTTP server with State Threads

BUILD_DEPENDS=	${LOCALBASE}/lib/libst.so.1:${PORTSDIR}/devel/st
LIB_DEPENDS=	st.1:${PORTSDIR}/devel/st

MD5_FILE=	${.CURDIR}/distinfo

MASTERDIR=	${.CURDIR}/../../www/thttpd
.include "${MASTERDIR}/Makefile"
