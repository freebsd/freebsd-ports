# New ports collection makefile for:    skim
# Date created:		21 July 2004
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	skim
PORTVERSION=	1.4.5
PORTREVISION=	3
CATEGORIES=	textproc kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scim

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An input method platform based on SCIM library and KDE/QT

LIB_DEPENDS=	scim-1.0:${PORTSDIR}/textproc/scim

USE_KDELIBS_VER=3
USE_PYTHON=	yes
USE_BZIP2=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
PYDISTUTILS_NOEGGINFO=	yes

CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PREFIX="${PREFIX}" \
		CXXFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__ ${CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"


.include <bsd.port.pre.mk>

.if ${PYTHON_REL} > 250
BROKEN=		Doesn't build with ${PYTHON_VERSION}
.endif

post-patch:
	${REINPLACE_CMD} s,bash,sh,g ${WRKSRC}/src/scim-panel-kde.in

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./configure

post-configure:
	${REINPLACE_CMD} \
		-e s,/usr/local/lib/pkgconfig,${PREFIX}/libdata/pkgconfig,g \
		-e s,/usr/lib/pkgconfig,${PREFIX}/libdata/pkgconfig,g \
		-e s,lib/pkgconfig,libdata/pkgconfig,g \
		${WRKSRC}/cache/pkg.cache.py
do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./scons

do-install:
	@cd ${WRKSRC} && ./scons install

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type pkg_info -D ${PKGNAME}

.include <bsd.port.post.mk>
