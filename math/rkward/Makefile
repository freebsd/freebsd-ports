# New ports collection makefile for:	RKWard
# Date created:        19 April 2006
# Whom:                thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	rkward
PORTVERSION=	0.4.7
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	IDE/GUI for the R-project

LIB_DEPENDS=	R.0:${PORTSDIR}/math/R

USE_KDELIBS_VER=3
USE_PHP=	yes
WANT_PHP_CLI=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\
		PTHREAD_LIBS="${PTHREAD_LIBS}"
INSTALLS_ICONS=	yes

WANT_FORTRAN=	yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran#42
F77=		gfortran#42
CONFIGURE_ENV+=	FC="${FC}" F77="${F77}" FFLAGS="${FFLAGS}"
MAKE_ENV+=	FC="${FC}" F77="${F77}" FFLAGS="${FFLAGS}"

DOCSDIR=	${PREFIX}/share/doc/HTML/en/rkward

.if defined(WITHOUT_NLS)
NLS=		"@comment "
.else
NLS=		""
.endif
PLIST_SUB+=	NLS=${NLS}

PHP2FIX=	rkward/plugins/makemakefileam.php	\
		rkward/settings/rksettingsmodulephp.cpp

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/bin/php|${LOCALBASE}/bin/php|'	\
		${PHP2FIX:S|^|${WRKSRC}/|}
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|rkward po doc debian|rkward po debian|'	\
		${WRKSRC}/Makefile.in
.endif
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e 's|SUBDIRS = rkward po|SUBDIRS = rkward|'	\
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
