# New ports collection makefile for:    skim
# Date created:		21 July 2004
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	skim
PORTVERSION=	1.2.0
PORTREVISION=	0
CATEGORIES=	textproc kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scim

MAINTAINER=	gaoj@cpsc.ucalgary.ca
COMMENT=	An input method platform based on SCIM library and KDE/QT

LIB_DEPENDS=	scim-1.0.6:${PORTSDIR}/textproc/scim

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=	15

USE_GNOME=	gnomehack

CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		Does not compile
.endif

.if ${OSVERSION} < 500035
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CONFIGURE_ENV+=	CXXFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/stlport ${CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -lstlport_gcc -lintl ${PTHREAD_LIBS}"
.else
CONFIGURE_ENV+=	CXXFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__ ${CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
.endif

pre-configure:
	${REINPLACE_CMD} "s,-pedantic,,g; \
		s,-pthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure
	${REINPLACE_CMD} "s, | .*freebsd\*)$$,*),g" ${WRKSRC}/admin/ltmain.sh

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type pkg_info -D ${PKGNAME}

.include <bsd.port.post.mk>
