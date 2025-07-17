PORTNAME=	flag-icons
PORTVERSION=	7.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Curated collection of all country flags rendered in PNG
WWW=		https://flagicons.lipis.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	convert:graphics/ImageMagick6 # ${IMAGEMAGICK_DEFAULT}

USE_GITHUB=	yes
GH_ACCOUNT=	lipis

NO_ARCH=	yes
NO_INSTALL=	yes

FLAGS_TOPDIR=	${PREFIX}/share/icons/${PORTNAME}
FLAG_SIZES=	16 24 32 48 64 96 128 192 256 # 512 adds 25+ MB for .tbz package

FLAVORS=	plain bordered rounded

.if ${FLAVOR:U:Nplain}
PKGNAMESUFFIX=	-${FLAVOR}
.endif

post-extract:
	@${TEST} $$(${FIND} ${WRKSRC}/flags -type f | wc -l) = $$((271 * 2))
	cd ${WRKSRC}/flags && ${SH} ${FILESDIR}/makeflags.sh add-missing-flags

do-build:
	cd ${BUILD_WRKSRC}/flags && JOBS=${MAKE_JOBS_NUMBER} ${SH} \
		${FILESDIR}/makeflags.sh ${FLAVOR} \
		${STAGEDIR}${FLAGS_TOPDIR}/${FLAVOR} ${FLAG_SIZES}

post-stage:
	cd ${STAGEDIR}${PREFIX} && ${FIND} share -type f >> ${TMPPLIST}

.include <bsd.port.mk>
