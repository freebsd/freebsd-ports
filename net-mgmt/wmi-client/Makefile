PORTNAME=	wmi
PORTVERSION=	1.3.16
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://dev.zenoss.org/trac/export/26435/trunk/inst/externallibs/ \
		http://www.openvas.org/download/wmi/ \
		http://mirrors.rit.edu/zi/
PKGNAMESUFFIX=	-client

MAINTAINER=	koichiro@rworks.jp
COMMENT=	DCOM/WMI client implementation

USES=		autoreconf:build gmake iconv tar:bzip2

MAKEFILE=	GNUmakefile
MAKE_ARGS+=	ZENHOME="${PREFIX}" INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_LIB="${INSTALL_LIB}"
ALL_TARGET=	build

PROGS=	bin/wmic bin/winexe

do-install:
.for x in ${PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/Samba/source/${x} ${STAGEDIR}${PREFIX}/${x}
.endfor

.include <bsd.port.mk>
