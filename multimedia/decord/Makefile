PORTNAME=	decord
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0-7
DISTVERSIONSUFFIX=	-gd2e5619
CATEGORIES=	multimedia # machine-learning

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	e543d1cbd4d21dbac85b1e78e43f59495c8ce78b.patch:-p1 # https://github.com/dmlc/decord/pull/309

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient video loader for deep learning
WWW=		https://github.com/dmlc/decord

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libdmlc.so:devel/dmlc-core

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
GH_TUPLE=	dmlc:dlpack:5c792ce:dlpack/3rdparty/dlpack

post-install:
	# install headers
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
