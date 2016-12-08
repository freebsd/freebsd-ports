# Created by: KIKUCHI Koichiro <koichiro@rworks.jp>
# $FreeBSD$

PORTNAME=	wmi
PORTVERSION=	1.3.16
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://dev.zenoss.org/trac/export/26435/trunk/inst/externallibs/ \
		http://www.openvas.org/download/wmi/ \
		http://mirrors.rit.edu/zi/
PKGNAMESUFFIX=	-client

MAINTAINER=	koichiro@rworks.jp
COMMENT=	DCOM/WMI client implementation

OPTIONS_DEFINE=	PYTHON
PYTHON_DESC=	Build Python bindings

USE_AUTOTOOLS=	autoconf:env autoheader:env
USES=		iconv gmake tar:bzip2

MAKEFILE=	GNUmakefile
MAKE_ARGS+=	ZENHOME="${PREFIX}" INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_LIB="${INSTALL_LIB}"
ALL_TARGET=	build

PROGS=	bin/wmic bin/winexe

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python
MAKE_ARGS+=	PYTHON="${PYTHON_CMD}" PY_LIBDIR="${PYTHONPREFIX_SITELIBDIR}"
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

.if !${PORT_OPTIONS:MPYTHON}
do-install:
.for x in ${PROGS}
	@${INSTALL_PROGRAM} ${WRKSRC}/Samba/source/${x} ${STAGEDIR}${PREFIX}/${x}
.endfor
.endif

.include <bsd.port.mk>
