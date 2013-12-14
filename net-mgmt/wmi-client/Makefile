# Created by: KIKUCHI Koichiro <koichiro@rworks.jp>
# $FreeBSD$

PORTNAME=		wmi
PORTVERSION=		1.3.16
CATEGORIES=		net-mgmt
MASTER_SITES=		http://dev.zenoss.org/trac/export/26435/trunk/inst/externallibs/ \
			http://www.openvas.org/download/wmi/ \
			http://mirrors.rit.edu/zi/
PKGNAMESUFFIX=		-client

MAINTAINER=		koichiro@rworks.jp
COMMENT=		DCOM/WMI client implementation

CONFLICTS=		zenoss-3*

USE_BZIP2=		yes
USE_AUTOTOOLS=		autoconf:env
USE_PYTHON_BUILD=	yes
USE_GMAKE=		yes
USES=			iconv
USE_LDCONFIG=		yes

MAKEFILE=		GNUmakefile
MAKE_ENV=		ZENHOME="${PREFIX}" PY_LIBDIR="${PYTHONPREFIX_SITELIBDIR}" PYTHON="${PYTHON_CMD}"
ALL_TARGET=		build

NO_STAGE=	yes
.include <bsd.port.mk>
