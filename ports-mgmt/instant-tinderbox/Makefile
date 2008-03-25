# New ports collection makefile for:    instant-tinderbox
# Date created:                         28 November 2005
# Whom:                                 Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	instant-tinderbox
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	ports-mgmt
DISTFILES=

MAINTAINER=	edwin@mavetju.org
COMMENT=	Build a whole bunch of often-required ports for a tinderbox environment

.if !defined(TINDERD_SLEEPTIME)
IGNORE=		should only be built from within a Tinderbox environment
.endif

###############################################################################

USE_SDL=	${_USE_SDL_ALL}

USE_GNOME=	gnomelibs

USE_KDELIBS_VER=	3
USE_QT_VER=		3

USE_MYSQL=	yes
USE_PGSQL=	yes
USE_BDB=	yes
USE_SQLITE=	yes

USE_APACHE=	yes

USE_PHP=	yes

USE_TCL_RUN=	yes
USE_TK_RUN=	yes

USE_XORG=	x11 xpm
USE_PERL5=	yes

USE_ICONV=	yes
USE_GETTEXT=	yes

USE_GMAKE=	yes

USE_GHOSTSCRIPT=yes
USE_BISON=	build
USE_FREETYPE=	yes
USE_GL=		yes
USE_OPENLDAP=	yes
USE_FAM=	yes
USE_PYTHON=	yes
USE_RUBY=	yes
USE_LINUX=	yes

.for v in 2.13 2.61
RUN_DEPENDS+=	autoconf-${v}:${PORTSDIR}/devel/autoconf${v:C/\.//}
.endfor
.for v in 1.4 1.5 1.6 1.7 1.8 1.9 1.10
RUN_DEPENDS+=	automake-${v}:${PORTSDIR}/devel/automake${v:C/\.//}
.endfor

###############################################################################

NO_BUILD=	yes
PLIST_FILES=
NO_WRKSUBDIR=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
