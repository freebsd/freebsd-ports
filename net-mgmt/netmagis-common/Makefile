# Created by: Pierre David <pdagog@gmail.com>, Jean Benoit <jean@unistra.fr>
# $FreeBSD$

PORTNAME?=	netmagis
DISTVERSION?=	2.2.2
PORTREVISION?=	1
CATEGORIES?=	net-mgmt
MASTER_SITES=	http://netmagis.org/files/
PKGNAMESUFFIX?=	-common

MAINTAINER?=	pdagog@gmail.com
COMMENT?=	Netmagis common infrastructure

# Portlint barfs about a MASTERDIR variable if the LICENSE block is defined (black magic?)
#LICENSE=	CECILL-B
#LICENSE_NAME=	CeCILL-B Free Software License Agreement
#LICENSE_FILE=	${WRKSRC}/LICENSE
#LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tcl:85+

USE_PGSQL=	pgtcl
WANT_PGSQL_VER=	91+

RUN_DEPENDS+=	dtplite:${PORTSDIR}/devel/tcllib

.if ${PKGNAMESUFFIX} != -common
RUN_DEPENDS+=	netmagis-config:${PORTSDIR}/net-mgmt/netmagis-common
.endif

.if ${PKGNAMESUFFIX} == -database
RUN_DEPENDS+=	pwgen:${PORTSDIR}/sysutils/pwgen
USE_PGSQL+=	server pltcl
.endif

.if ${PKGNAMESUFFIX} == -www
USE_TEX=	tex
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz \
		pwgen:${PORTSDIR}/sysutils/pwgen
.endif

.if ${PKGNAMESUFFIX} == -topo
USE_RC_SUBR=	topographd toposendd
SUB_LIST=	TCLSH=${TCLSH}
RUN_DEPENDS+=	rancid-run:${PORTSDIR}/net-mgmt/rancid \
		fping:${PORTSDIR}/net/fping
.endif

.if ${PKGNAMESUFFIX} == -metro
USES+=		perl5

RUN_DEPENDS+=	p5-DBD-Pg>0:${PORTSDIR}/databases/p5-DBD-Pg \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		p5-SNMP_Session>=0:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		p5-RRDTool-OO>=0:${PORTSDIR}/devel/p5-RRDTool-OO

USES+=		shebangfix
SHEBANG_FILES=	metro/bin/metrocreatedb metro/bin/metropoller metro/bin/metropoller-run
.endif

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

.if !target(post-install)
post-install:
	@if [ -f ${PKGMESSAGE} ] ; then ${CAT} ${PKGMESSAGE} ; fi
.endif

.include <bsd.port.mk>
