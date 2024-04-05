PORTNAME=	octave-forge-odbc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.2
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS+=	libodbc.so:databases/unixODBC \
		libsqlite3odbc.so:databases/sqliteodbc

USES=		octave autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	octave-odbc

GNU_CONFIGURE=	yes

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

.include <bsd.port.mk>
