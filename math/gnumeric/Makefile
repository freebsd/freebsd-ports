# New ports collection makefile for:	gnumeric
# Date created:				08 October 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnumeric
PORTVERSION=	1.0.0
CATEGORIES?=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnumeric

MAINTAINER?=	gnome@FreeBSD.org

LIB_DEPENDS=	gnomeole2.0:${PORTSDIR}/devel/libole2 \
		gbrun.0:${PORTSDIR}/lang/gnomebasic \
		giconv.2:${PORTSDIR}/converters/libiconv \
		psiconv.7:${PORTSDIR}/converters/psiconv

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lintl -lgiconv ${PTHREAD_LIBS}"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

PLIST_SUB=	VERSION=${PORTVERSION}-bonobo

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'
	@find ${WRKSRC}/plugins/excel -name "*.[ch]" | xargs ${PERL} -pi -e \
		's|iconv\.h|giconv.h|g'

post-install:
.for dir in share/gnome lib
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/${dir}/gnumeric
.endfor

.include <bsd.port.mk>
