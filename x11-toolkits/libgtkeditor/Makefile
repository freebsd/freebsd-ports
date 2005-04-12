# New ports collection makefile for:	libgtkeditor
# Date created:				25 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgtkeditor
PORTVERSION=	0.1.8
PORTREVISION=	1
CATEGORIES=	x11-toolkits editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/lib//}
DISTNAME=	${PORTNAME:S/lib//}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A source code editor widget for GTK+

LIB_DEPENDS=	unicode.0:${PORTSDIR}/devel/libunicode

WANT_AUTOMAKE_VER=15
WANT_AUTOCONF_VER=253
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_INC_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
CFLAGS+=	-fPIC

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	${MACHINE_ARCH}-portbld-freebsd${OSREL}

pre-configure:
.for file in install-sh mkinstalldirs
	@${LN} -sf ${AUTOMAKE_DIR}/${file} ${WRKSRC}/${file}
.endfor
	@${RM} ${WRKSRC}/config.guess ${WRKSRC}/config.sub
	@${TOUCH} ${WRKSRC}/config.sub

post-configure:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/scanner.c

pre-install:
	@${MKDIR} ${PREFIX}/include/tktext-port

.include <bsd.port.mk>
