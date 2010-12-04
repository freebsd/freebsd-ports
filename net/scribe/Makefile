# New ports collection makefile for:	scribe
# Date created:         2010-07-15
# Whom:                 Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$
#

PORTNAME=	scribe
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://cloud.github.com/downloads/facebook/scribe/

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Aggregating log data streamed in real time

BUILD_DEPENDS=	fb303>0:${PORTSDIR}/devel/fb303
LIB_DEPENDS=	boost_system:${PORTSDIR}/devel/boost-libs \
		event:${PORTSDIR}/devel/libevent \
		thrift:${PORTSDIR}/devel/thrift
RUN_DEPENDS=	p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Thrift>0:${PORTSDIR}/devel/p5-Thrift

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

post-extract:
	${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local/scribe|${LOCALBASE}/etc|' ${WRKSRC}/src/env_default.h

post-build:
	${LOCALBASE}/bin/thrift -o ${WRKSRC} -I ${LOCALBASE}/share --gen "perl" ${WRKSRC}/if/scribe.thrift
	cd ${WRKSRC} && ${PATCH} < ${FILESDIR}/scribe.pm.patch

post-install:
	${MKDIR} ${PREFIX}/${SITE_PERL_REL}/Scribe/Thrift
	${CP} ${WRKSRC}/gen-perl/*.pm ${PREFIX}/${SITE_PERL_REL}/Scribe/Thrift
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/* ${EXAMPLESDIR}

.include <bsd.port.mk>
