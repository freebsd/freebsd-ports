# New ports collection makefile for:  .LRN (dotLRN)
# Date created:         July 2005
# Whom:                 Aldert Nooitgedagt <nooitgedagt.net>
#
# $FreeBSD$
#

PORTNAME=	dotlrn
DISTVERSION=	2.5.0
MASTER_SITES=	http://openacs.org/projects/dotlrn/download/download/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	OpenACS-based e-learning platform

DIST_REV_ID=	2984410

OPENACS_USER?=	dotlrn
OPENACS_GROUP?=	dotlrn
OPENACS_DB?=	dotlrn

OPENACSBASE=	${PREFIX}/dotlrn
OPENACSNAME=	.LRN

BASE_INSTALL=	bin content-repository-content-files log packages tcl www install.xml

DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo

MASTERDIR=	${.CURDIR}/../openacs

.include "${MASTERDIR}/Makefile"
