# New ports collection makefile for:	wmi
# Date created:		2011-11-25
# Whom:			KIKUCHI Koichiro <koichiro@rworks.jp>
#
# $FreeBSD$
#

PORTNAME=		wmi
PORTVERSION=		1.3.16
CATEGORIES=		net-mgmt
MASTER_SITES=		http://dev.zenoss.org/svn/trunk/inst/externallibs/ \
			ftp://ftp.mk.bsdclub.org/pub/FreeBSD/distfiles/
PKGNAMESUFFIX=		-client

MAINTAINER=		koichiro@rworks.jp
COMMENT=		DCOM/WMI client implementation

CONFLICTS=		zenoss-3*

USE_BZIP2=		yes
USE_AUTOTOOLS=		autoconf:env
USE_PYTHON_BUILD=	yes
USE_GMAKE=		yes
USE_ICONV=		yes
USE_LDCONFIG=		yes

#BUILD_DEPENDS+=		gnutls.47:${PORTSDIR}/security/gnutls
#RUN_DEPENDS+=		gnutls.47:${PORTSDIR}/security/gnutls

MAKEFILE=		GNUmakefile
MAKE_ENV=		ZENHOME="${PREFIX}" PY_LIBDIR="${PYTHONPREFIX_SITELIBDIR}"
ALL_TARGET=		build

.include <bsd.port.pre.mk>

do-configure:
# do noting

.include <bsd.port.post.mk>
