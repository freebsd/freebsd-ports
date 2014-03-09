# Created by: Pierre David <pdagog@gmail.com>, Jean Benoit <jean@unistra.fr>
# $FreeBSD$

PORTNAME?=	netmagis
DISTVERSION?=	2.2.0
PORTREVISION?=	1
CATEGORIES?=	net-mgmt
MASTER_SITES=	http://netmagis.org/files/
PKGNAMESUFFIX?=	-common

MAINTAINER?=	pdagog@gmail.com
COMMENT?=	Netmagis common infrastructure

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
USE_APACHE=	22+
USE_TEX=	tex
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz \
		pwgen:${PORTSDIR}/sysutils/pwgen \
		${LOCALBASE}/libexec/apache22/mod_auth_pgsql.so:${PORTSDIR}/www/mod_auth_pgsql2
# FIXME compile apache22 with option mod_auth_ldap
# FIXME add ap22-mod_auth_cas
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
.endif

# Variables used in netmagis Makefiles
MAKE_ARGS+=	DESTDIR=${DESTDIR} PREFIX=${PREFIX}
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
