# New ports collection makefile for:	fusefs-s3fs
# Date created:		2009-04-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	s3fs
DISTVERSION=	1.19
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	gslin@gslin.org
COMMENT=	FUSE-based file system backed by Amazon S3

BUILD_DEPENDS=	${LOCALBASE}/bin/gnome-config:${PORTSDIR}/x11/gnome-libs
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		fuse:${PORTSDIR}/sysutils/fusefs-libs \
		xml2:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/s3fs

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
