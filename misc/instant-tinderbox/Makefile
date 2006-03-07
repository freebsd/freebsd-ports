# New ports collection makefile for:    instant-tinderbox
# Date created:                         28 November 2005
# Whom:                                 Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	instant-tinderbox
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	misc
DISTFILES=

MAINTAINER=	edwin@mavetju.org
COMMENT=	Build a whole bunch of often-required ports for a tinderbox environment

.if !defined(TINDERD_SLEEPTIME)
IGNORE=		should only be build from within a Tinderbox environment
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

WANT_PHP_PEAR=	yes
USE_PHP=	yes

USE_TCL=	yes
USE_TK=		yes

USE_XLIB=	yes
USE_PERL5=	yes

USE_ICONV=	yes
USE_GETTEXT=	yes

USE_GMAKE=	yes

USE_GHOSTSCRIPT=yes
USE_BISON=	yes
USE_FREETYPE=	yes
USE_GL=		yes
USE_XPM=	yes
USE_OPENLDAP=	yes
USE_FAM=	yes
USE_PYTHON=	yes
USE_RUBY=	yes
USE_LINUX=	yes

.for v in 213 253 259
RUN_DEPENDS+=	autoconf${v}:${PORTSDIR}/devel/autoconf${v}
.endfor
.for v in 14 15 19
RUN_DEPENDS+=	automake${v}:${PORTSDIR}/devel/automake${v}
.endfor

###############################################################################

NO_BUILD=	yes
PLIST_FILES=
NO_WRKSUBDIR=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
