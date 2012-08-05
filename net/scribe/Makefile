# New ports collection makefile for:	scribe
# Date created:         2010-07-15
# Whom:                 Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$
#

PORTNAME=	scribe
DISTVERSION=	2.2.2012.01.07
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/facebook/scribe/tarball/${GITVERSION}/
DISTNAME=	facebook-scribe-${GITVERSION}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Aggregating log data streamed in real time

BUILD_DEPENDS=	fb303>0:${PORTSDIR}/devel/fb303
LIB_DEPENDS=	boost_system:${PORTSDIR}/devel/boost-libs \
		event:${PORTSDIR}/devel/libevent \
		thrift:${PORTSDIR}/devel/thrift
RUN_DEPENDS=	p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Thrift>0:${PORTSDIR}/devel/p5-Thrift \
		${PYTHON_SITELIBDIR}/thrift/__init__.py:${PORTSDIR}/devel/py-thrift

GITVERSION=	63e4824
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/${DISTNAME}

ACLOCAL_ARGS=	-I ./aclocal
AUTOMAKE_ARGS=	-a
CONFIGURE_ARGS=	--with-boost-filesystem=boost_filesystem \
		--with-boost-system=boost_system \
		PY_PREFIX="${PREFIX}"
PLIST_SUB+=	PYTHON_VERSION_SHORTNAME="${PYTHON_VERSION_SHORTNAME}"
PYTHON_VERSION_SHORTNAME=	${PYTHON_VERSION:S/thon//}
USE_AUTOTOOLS=	aclocal automake autoconf
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_RC_SUBR=	${PORTNAME}

post-build:
	${LOCALBASE}/bin/thrift -o ${WRKSRC} -I ${LOCALBASE}/share --gen "perl" ${WRKSRC}/if/scribe.thrift

post-install:
	${MKDIR} ${PREFIX}/${SITE_PERL_REL}/Scribe/Thrift
	${CP} -R ${WRKSRC}/gen-perl/ ${PREFIX}/${SITE_PERL_REL}
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/* ${EXAMPLESDIR}

.include <bsd.port.mk>
