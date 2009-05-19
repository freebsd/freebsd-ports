# New ports collection makefile for:	RKWard
# Date created:        19 April 2006
# Whom:                thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	rkward
DISTVERSION=	0.4.9a
PORTREVISION=	3
PORTEPOCH=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	IDE/GUI for the R-project

LIB_DEPENDS=	R.0:${PORTSDIR}/math/R

CONFLICTS=	rkward-kde4-0.5.*

USE_KDELIBS_VER=3
USE_PHP=	yes
WANT_PHP_CLI=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-fast-perl
INSTALLS_ICONS=	yes

USE_FORTRAN=	yes
FORTRANLIBDIR2=	`${DIRNAME} \\`${FC} -print-libgcc-file-name\\``/../../../

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
	${REINPLACE_CMD} -e 's|-lgfortran|-L${FORTRANLIBDIR2} -lgfortran|'	\
		${WRKSRC}/${CONFIGURE_SCRIPT}
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|rkward po doc|rkward po|'	\
		${WRKSRC}/Makefile.in
.endif
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e 's|SUBDIRS = rkward po|SUBDIRS = rkward|'	\
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
