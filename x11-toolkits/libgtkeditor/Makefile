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

BUILD_DEPENDS=	${LOCALBASE}/share/automake/install-sh:${PORTSDIR}/devel/automake
LIB_DEPENDS=	unicode.0:${PORTSDIR}/devel/libunicode

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	${MACHINE_ARCH}-portbld-freebsd${OSREL}

pre-configure:
.for file in install-sh mkinstalldirs
	@${LN} -sf ${LOCALBASE}/share/automake/${file} ${WRKSRC}/${file}
.endfor
	@${RM} ${WRKSRC}/config.guess ${WRKSRC}/config.sub
	@${TOUCH} ${WRKSRC}/config.sub

post-configure:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/scanner.c

pre-install:
	@${MKDIR} ${PREFIX}/include/tktext-port

.include <bsd.port.mk>
