# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	scribe
DISTVERSION=	2.2.2013.04.15
PORTREVISION=	10
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Aggregating log data streamed in real time

LICENSE=	APACHE20

BUILD_DEPENDS=	fb303>0:devel/fb303 \
		thrift:devel/thrift
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libevent.so:devel/libevent \
		libthrift.so:devel/thrift-cpp
RUN_DEPENDS=	p5-Class-Accessor>0:devel/p5-Class-Accessor \
		p5-Thrift>0:devel/p5-Thrift \
		${PYTHON_PKGNAMEPREFIX}thrift>0:devel/py-thrift

BROKEN_powerpc64=	Does not build

USE_GITHUB=	yes
GH_ACCOUNT=	facebookarchive
GH_TAGNAME=	7359a09

USES=		autoreconf compiler gmake perl5 python
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost-filesystem=boost_filesystem \
		--with-boost-system=boost_system \
		PY_PREFIX="${PREFIX}"
USE_RC_SUBR=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's/^AM_INIT_AUTOMAKE/#/' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e '/boost/! s/shared_ptr/boost::&/g' \
		${WRKSRC}/src/conf.cpp \
		${WRKSRC}/src/conn_pool.cpp \
		${WRKSRC}/src/dynamic_bucket_updater.cpp \
		${WRKSRC}/src/env_default.cpp \
		${WRKSRC}/src/file.cpp \
		${WRKSRC}/src/scribe_server.cpp \
		${WRKSRC}/src/store.cpp \
		${WRKSRC}/src/store_queue.cpp

post-configure:
	@${REINPLACE_CMD} 's/-O3/${CXXFLAGS}/' ${WRKSRC}/src/Makefile

post-build:
	${LOCALBASE}/bin/thrift -o ${WRKSRC} -I ${LOCALBASE}/share --gen "perl" ${WRKSRC}/if/scribe.thrift

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Scribe/Thrift
	(cd ${WRKSRC}/gen-perl && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SITE_PERL_REL})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
USE_CXXSTD=	c++11
.endif

.include <bsd.port.post.mk>
