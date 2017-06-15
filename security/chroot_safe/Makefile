# Created by: Gabor Kovesdan
# $FreeBSD$

PORTNAME=	chroot_safe
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	security sysutils
MASTER_SITES=	SF/chrootsafe/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to chroot softwares easily

LICENSE=	MIT

USES=		tar:tgz
GNU_CONFIGURE=	yes

PLIST_FILES=	man/man1/chroot_safe.1.gz sbin/chroot_safe libexec/chroot_safe/chroot_safe.so

post-patch:
	@${REINPLACE_CMD} -e  's|CXX=g++|CXX?=c++|' \
		-e 's|-o chroot_safe.so|chroot_safe.cpp -o chroot_safe.so|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's|chroot(1)|chroot(8)|' ${WRKSRC}/chroot_safe.1.in
	@${REINPLACE_CMD} 's|putenv|unsetenv|' ${WRKSRC}/chroot_safe.cpp

.include <bsd.port.mk>
