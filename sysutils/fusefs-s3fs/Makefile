# New ports collection makefile for:	fusefs-s3fs
# Date created:		2009-04-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	s3fs
DISTVERSION=	1.19
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	gslin@gslin.org
COMMENT=	FUSE-based file system backed by Amazon S3

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		xml2:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_FUSE=	yes
PLIST_FILES=	bin/s3fs

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
