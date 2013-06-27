# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	s3fs
DISTVERSION=	1.71
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	gslin@gslin.org
COMMENT=	FUSE-based file system backed by Amazon S3

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		xml2:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/s3fs
USES=		fuse

MAN1=		s3fs.1

post-patch:
	${REINPLACE_CMD} -e 's/libcrypto >= 0.9//g' ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
