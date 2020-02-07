# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	s3fs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.86
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	FUSE-based file system backed by Amazon S3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libxml2.so:textproc/libxml2

USES=		autoreconf fuse pkgconfig ssl

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	s3fs-fuse
GH_PROJECT=	s3fs-fuse

PLIST_FILES=	bin/s3fs man/man1/s3fs.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's/libcrypto >= 0.9//' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e '/DEPS_LIBS/s/$$/ -lcrypto/' \
		${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
