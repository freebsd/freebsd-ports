# New ports collection makefile for:	libgtkeditor
# Date created:				25 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgtkeditor
PORTVERSION= 	0.1.8
CATEGORIES=	x11-toolkits editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/lib//}
DISTNAME=	${PORTNAME:S/lib//}-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/share/automake/install-sh:${PORTSDIR}/devel/automake
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		unicode.0:${PORTSDIR}/devel/libunicode

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-configure:
.for file in install-sh config.sub mkinstalldirs
	@${LN} -sf ${LOCALBASE}/share/automake/${file} ${WRKSRC}/${file}
.endfor

post-configure:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/scanner.c

pre-install:
	@${MKDIR} ${PREFIX}/include/tktext-port

.include <bsd.port.mk>
