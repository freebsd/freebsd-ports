# Created by: Eric L. Hernes <erich@rrnet.com>
# $FreeBSD$

PORTNAME=	xlispstat
PORTVERSION=	3.52.23
CATEGORIES=	math lang lisp
MASTER_SITES=	http://homepage.stat.uiowa.edu/~luke/xls/xlispstat/3-52/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Statistics/X11 based lisp interpreter

LICENSE=	BSD

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	UCFLAGS="${CFLAGS}"
ALL_TARGET=	${PORTNAME}
MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
