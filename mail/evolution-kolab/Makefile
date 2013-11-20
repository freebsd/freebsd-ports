# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/mail/evolution-kolab/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	evolution-kolab
PORTVERSION=	3.6.4
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Kolab groupware connector for evolution

BUILD_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution \
		gperf>=3.0.3:${PORTSDIR}/devel/gperf
LIB_DEPENDS=	libgmime-2.4.so:${PORTSDIR}/mail/gmime24
RUN_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution

EVO_VER=	3.6.0
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_SQLITE=	3
MAKE_JOBS_UNSAFE=yes
USE_GNOME=	gnomeprefix intlhack ltasneededhack libxml2 gconf2 
CONFIGURE_ENV=	ac_cv_path_GPERF=${LOCALBASE}/bin/gperf
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

VERSION=	3.6
PLIST_SUB=	VERSION=${VERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,prefix}/doc/evolution_kolab,prefix}/share/doc/evolution_kolab,g' \
		${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libekolabconv.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution-data-server/*/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution/${VERSION}/*/*.so

.include <bsd.port.post.mk>
