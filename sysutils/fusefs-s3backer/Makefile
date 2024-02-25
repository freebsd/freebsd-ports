PORTNAME=	s3backer
DISTVERSION=	1.5.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://s3.amazonaws.com/archie-public/s3backer/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	bsdports@staktrace.com
COMMENT=	FUSE filesystem that uses Amazon S3 as a backing store
WWW=		https://github.com/archiecobbs/s3backer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
# Need to have curl/curl.h on the include path. Is there a better
# way to do this than sending CPPFLAGS to configure?
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include"

USES=		fuse pkgconfig ssl

.include <bsd.port.mk>
