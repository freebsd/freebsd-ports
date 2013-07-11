# Created by: Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
# $FreeBSD$

PORTNAME=	klamav
PORTVERSION=	0.46
PORTREVISION=	7
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/Source%20%28For%20ClamAV%20and%20gt_%3D%200.9x%29/KlamAV-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE 3 front-end to Clam Anti-Virus

LIB_DEPENDS=	clamav:${PORTSDIR}/security/clamav

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}-${PORTVERSION}

PREFIX=		${KDE_PREFIX}

USES=		gettext gmake pkgconfig
USE_SQLITE=	3
INSTALLS_ICONS=	yes

USE_AUTOTOOLS=	libtool aclocal
LIBTOOLFILES=	acinclude.m4 configure
LDFLAGS+=	${PTHREAD_LIBS} -lintl -L${PREFIX}/lib
CONFIGURE_ARGS+=--with-qt-dir=${QT_PREFIX} \
		--without-included-sqlite

USE_KDELIBS_VER=	3

pre-configure:
	@${CP} ${LTMAIN} ${WRKSRC}/admin
	@${CP} ${LIBTOOL_M4} ${WRKSRC}/admin
	@${CP} ${LOCALBASE}/include/clamav-config.h ${WRKSRC}/src/klamd

.include <bsd.port.mk>
