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

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:textproc/flex
.endif

post-configure:
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/extra-patch-c_Makefile
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/extra-patch-libtool
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
	${REINPLACE_CMD} -e 's|flex|${LOCALBASE}/bin/flex|' \
		${WRKSRC}/c/dsls/Makefile
.endif

.include <bsd.port.post.mk>
