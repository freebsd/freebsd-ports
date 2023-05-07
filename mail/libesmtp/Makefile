PORTNAME=	libesmtp
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	mail

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for posting electronic mail
WWW=		http://www.stafford.uklinux.net/libesmtp/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe meson pkgconfig ssl

CFLAGS+=	-D__BSD_VISIBLE
MESON_ARGS=	--default-library=both -Dbdat=true -Detrn=true -Dlwres=disabled -Dpthreads=enabled -Dtls=enabled -Dxdg=true -Dxusr=true
USE_LDCONFIG=	yes

CPE_VENDOR=	libesmtp_project

USE_GITHUB=	yes
GH_PROJECT=	libESMTP

.include <bsd.port.mk>
