# New ports collection makefile for:  .LRN (dotLRN)
# Date created:         July 2005
# Whom:                 Aldert Nooitgedagt <nooitgedagt.net>
#
# $FreeBSD$
#

PORTNAME=	dotlrn
PORTVERSION=	2.2.1
MASTER_SITES=	http://openacs.org/projects/dotlrn/download/download/
EXTRACT_SUFX=	.tgz?revision_id=559791

MAINTAINER=	mm@FreeBSD.org
COMMENT=	OpenACS-based e-learning platform for high-traffic communities

OPENACS_USER?=  dotlrn
OPENACS_DB?=	dotlrn
OPENACS_GROUP?= www

OPENACSBASE=	${TARGETDIR}/dotlrn
OPENACSNAME=	.LRN

BASE_INSTALL=	bin content-repository-content-files log packages tcl www install.xml

DESCR=		${.CURDIR}/pkg-descr
MD5_FILE=	${.CURDIR}/distinfo

MASTERDIR=	${.CURDIR}/../openacs

.include "${MASTERDIR}/Makefile"
