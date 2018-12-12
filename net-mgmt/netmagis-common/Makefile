# Created by: Pierre David <pdagog@gmail.com>, Jean Benoit <jean@unistra.fr>
# $FreeBSD$

PORTNAME?=	netmagis
PORTVERSION?=	2.3.4
PORTREVISION=	1
CATEGORIES?=	net-mgmt
MASTER_SITES=	http://netmagis.org/files/
PKGNAMESUFFIX?=	-common

MAINTAINER?=	pdagog@gmail.com
COMMENT?=	Netmagis common infrastructure

LICENSE=	CECILL-B
LICENSE_NAME=	CeCILL-B Free Software License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS+=	dtplite:devel/tcllib

NO_ARCH?=	yes
USES+=		pgsql:9.1+ tcl:85+
WANT_PGSQL+=	pgtcl

SLAVEDIRS=	net-mgmt/netmagis-common \
	net-mgmt/netmagis-database \
	net-mgmt/netmagis-detecteq \
	net-mgmt/netmagis-metro \
	net-mgmt/netmagis-servers \
	net-mgmt/netmagis-topo \
	net-mgmt/netmagis-utils \
	net-mgmt/netmagis-www

# Variables used in netmagis Makefiles
MAKE_ARGS+=	DESTDIR=${STAGEDIR}${DESTDIR} PREFIX=${PREFIX}
MAKE_ARGS+=	TCLSH=${TCLSH} TCLCONF=${TCL_LIBDIR}/tclConfig.sh

.if ${PKGNAMESUFFIX} == -topo || ${PKGNAMESUFFIX} == -www
ALL_TARGET=build${PKGNAMESUFFIX?=}
.else
ALL_TARGET=nothing
.endif

INSTALL_TARGET=	install${PKGNAMESUFFIX}

# Change "cd foo; make" into "$(MAKE) -C foo" to unbreak parallel builds
post-patch:
	@${FIND} ${WRKSRC} -type f -name Makefile -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -E 's,cd(.+) (;|&&) make,$$(MAKE) -C\1,'
	@${REINPLACE_CMD} -E 's,cd (.+) ; (ln -s en ),\2\1/,' \
		${WRKSRC}/www/Makefile
	${REINPLACE_CMD} '/NMVARDIR/s/$$(PREFIX)//' ${WRKSRC}/Makefile

.include <bsd.port.mk>
