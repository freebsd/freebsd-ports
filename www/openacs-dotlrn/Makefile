# Created by: Aldert Nooitgedagt <nooitgedagt.net>
# $FreeBSD$

PORTNAME=	dotlrn
DISTVERSION=	2.5.0
MASTER_SITES=	http://openacs.org/projects/dotlrn/download/download/

MAINTAINER=	ports@FreeBSD.org
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

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
