# New ports collection makefile for:   klamav
# Date created:        30 July 2005
# Whom:                Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
#
# $FreeBSD$
#

PORTNAME=	klamav
PORTVERSION=	0.46
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	A KDE 3 front-end to Clam Anti-Virus

LIB_DEPENDS=	clamav:${PORTSDIR}/security/clamav

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}-${PORTVERSION}

PREFIX=		${KDE_PREFIX}

USE_GMAKE=	yes
USE_SQLITE=	3
USE_GNOME=	pkgconfig
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

USE_AUTOTOOLS=	libtool:15 aclocal:19

CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS} -lintl -L${PREFIX}/lib"
CONFIGURE_ARGS+=--with-qt-dir=${QT_PREFIX} \
		--without-included-sqlite

USE_KDELIBS_VER=	3

.include <bsd.port.pre.mk>

pre-configure:
	@${CP} ${LTMAIN} ${WRKSRC}/admin
	@${CP} ${LIBTOOL_M4} ${WRKSRC}/admin
	@${CP} ${PREFIX}/include/clamav-config.h ${WRKSRC}/src/klamd

.include <bsd.port.post.mk>
