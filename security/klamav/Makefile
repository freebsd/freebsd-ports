# New ports collection makefile for:   klamav
# Date created:        30 July 2005
# Whom:                Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
#
# $FreeBSD$
#

PORTNAME=	klamav
PORTVERSION=	0.22
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	klamav
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	A KDE 3 front-end to Clam Anti-Virus

LIB_DEPENDS=	clamav:${PORTSDIR}/security/clamav

USE_KDELIBS_VER=3
PREFIX=         ${KDE_PREFIX}

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_BZIP2=      yes
USE_GMAKE=      yes

GNU_CONFIGURE=  yes

CONFIGURE_ENV+= LDFLAGS=${PTHREAD_LIBS}
CONFIGURE_ARGS+= --with-qt-dir=${X11BASE}

.include <bsd.port.mk>
