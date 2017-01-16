# $FreeBSD$

PORTNAME=	miller
PORTVERSION=	3.3.2
DISTVERSIONPREFIX=v
CATEGORIES=	textproc

MAINTAINER=	jungleboogie0+mlr@gmail.com
COMMENT=	Sed/awk/cut/join/sort for name-indexed data such as CSV

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	johnkerl
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/mlr man/man1/mlr.1.gz

BROKEN_aarch64=		Fails to compile: undefined reference to .mcount

post-configure:
	${PATCH} -d ${PATCH_WRKSRC} ${PATCH_ARGS} < ${FILESDIR}/extra-patch-c_Makefile
	${PATCH} -d ${PATCH_WRKSRC} ${PATCH_ARGS} < ${FILESDIR}/extra-patch-libtool

.include <bsd.port.mk>
