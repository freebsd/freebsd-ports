# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	s3fs
DISTVERSION=	1.71
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	gslin@gslin.org
COMMENT=	FUSE-based file system backed by Amazon S3

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libxml2.so:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/s3fs man/man1/s3fs.1.gz
USES=		fuse pkgconfig
USE_OPENSSL=	yes

post-patch:
	${REINPLACE_CMD} -e 's/libcrypto >= 0.9//g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e '/^DEPS_LIBS =/s/$$/ -lcrypto/' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
