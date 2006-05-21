# Ports collection Makefile for:	chroot_safe
# Date created:				11 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	chroot_safe
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	security sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	chrootsafe
EXTRACT_SUFX=	.tgz

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	A tool to chroot softwares easily

GNU_CONFIGURE=YES

MAN1=		chroot_safe.1
PLIST_FILES=	sbin/chroot_safe libexec/chroot_safe/chroot_safe.so
PLIST_DIRS=	libexec/chroot_safe

post-patch:
	${REINPLACE_CMD} -e  's|CXX=g++|CXX?=c++|' \
		-e 's|-o chroot_safe.so|chroot_safe.cpp -o chroot_safe.so|' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} 's|chroot(1)|chroot(8)|' ${WRKSRC}/chroot_safe.1.in
	${REINPLACE_CMD} 's|putenv|unsetenv|' ${WRKSRC}/chroot_safe.cpp

.include <bsd.port.mk>
