# New ports collection makefile for:   klamav
# Date created:        30 July 2005
# Whom:                Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
#
# $FreeBSD$
#

PORTNAME=	klamav
PORTVERSION=	0.37
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	klamav
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	A KDE 3 front-end to Clam Anti-Virus

LIB_DEPENDS=	clamav:${PORTSDIR}/security/clamav \
		sqlite3:${PORTSDIR}/databases/sqlite3

PREFIX=		${KDE_PREFIX}
DOCSDIR=	${PREFIX}/share/doc/HTML/en/klamav02

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool:15

CONFIGURE_ENV=	LDFLAGS=${PTHREAD_LIBS}
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE} \
		--without-included-sqlite

USE_KDELIBS_VER=	3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	klamav doesn't compile on FreeBSD 4.X
.endif

.include <bsd.port.post.mk>
