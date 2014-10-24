# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	scribe
DISTVERSION=	2.2.2013.04.15
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://github.com/facebookarchive/scribe/tarball/${GITVERSION}/
DISTNAME=	facebook-scribe-${GITVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Aggregating log data streamed in real time

LICENSE=	APACHE20

BUILD_DEPENDS=	fb303>0:${PORTSDIR}/devel/fb303 \
		thrift:${PORTSDIR}/devel/thrift
LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libevent.so:${PORTSDIR}/devel/libevent2 \
		libthrift.so:${PORTSDIR}/devel/thrift-cpp
RUN_DEPENDS=	p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Thrift>0:${PORTSDIR}/devel/p5-Thrift \
		${PYTHON_SITELIBDIR}/thrift/__init__.py:${PORTSDIR}/devel/py-thrift

GITVERSION=	7359a09
WRKSRC=		${WRKDIR}/facebookarchive-${PORTNAME}-${GITVERSION}

ACLOCAL_ARGS=	-I ./aclocal
AUTOMAKE_ARGS=	-a
CONFIGURE_ARGS=	--with-boost-filesystem=boost_filesystem \
		--with-boost-system=boost_system \
		PY_PREFIX="${PREFIX}"
USE_AUTOTOOLS=	aclocal automake autoconf
USE_RC_SUBR=	${PORTNAME}
USES=		gmake perl5 python

post-patch:
	${REINPLACE_CMD} -e 's/^AM_INIT_AUTOMAKE/#/' ${WRKSRC}/configure.ac

post-build:
	${LOCALBASE}/bin/thrift -o ${WRKSRC} -I ${LOCALBASE}/share --gen "perl" ${WRKSRC}/if/scribe.thrift

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Scribe/Thrift
	(cd ${WRKSRC}/gen-perl && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SITE_PERL_REL})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
