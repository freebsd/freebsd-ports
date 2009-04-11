# New ports collection makefile for:	fusefs-s3fs
# Date created:		2009-04-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	s3fs
DISTVERSION=	r177
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	fusefs-
DISTFILES=	${PORTNAME}-${DISTVERSION}-source${EXTRACT_SUFX}

MAINTAINER=	gslin@gslin.org
COMMENT=	FUSE-based file system backed by Amazon S3

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		fuse:${PORTSDIR}/sysutils/fusefs-libs \
		iconv:${PORTSDIR}/converters/iconv \
		xml2:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

PLIST_FILES=	sbin/s3fs
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/s3fs ${PREFIX}/sbin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
