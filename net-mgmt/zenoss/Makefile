# New ports collection makefile for:	zenoss
# Date created:		19 April 2011
# Whom:			Phil Phillips
#
# $FreeBSD$
#

PORTNAME=	zenoss
PORTVERSION=	3.1.0
CATEGORIES=	net-mgmt java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-3.1/${PORTNAME}-${PORTVERSION}:source1 \
		http://dev.sencha.com/deploy/:source2
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz:source1 \
		JSBuilder2.zip:source2
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	pphillips@experts-exchange.com
COMMENT=	Application, server, and network management platform

BUILD_DEPENDS+=	swig>=1.3:${PORTSDIR}/devel/swig13 \
		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS+=	bash>=4.1:${PORTSDIR}/shells/bash \
		net-snmp>=5.5:${PORTSDIR}/net-mgmt/net-snmp \
		liberation-fonts-ttf>=1.05:${PORTSDIR}/x11-fonts/liberation-fonts-ttf

LICENSE=	GPLv2

USE_RC_SUBR=	zenoss
USE_MYSQL=	client
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_BUILD=	yes
USE_AUTOTOOLS=	autoconf:env

USERS=		zenoss
GROUPS=		zenoss

SUB_FILES=	pkg-install profile local.conf
SUB_LIST=	ZENHOME=${ZENHOME}
PLIST_SUB=	ZENHOME=${ZENHOME:S,${PREFIX}/,,} \
		OSVERSION_MAJOR=${INDEXFILE:S/INDEX-//}
ZENHOME=	${PREFIX}/${PORTNAME}
MANPREFIX?=	${ZENHOME}/share
.include "${.CURDIR}/Makefile.man"
BUILD_ENV=	PYTHONDONTWRITEBYTECODE=yes

.include <bsd.port.pre.mk>

.if (${ARCH} == amd64)
PLIST_SUB+=	32BIT_ONLY="@comment "
.else
PLIST_SUB+=	32BIT_ONLY=""
.endif

.if (${OSVERSION} >= 900000)
PLIST_SUB+=	OSSAUDIODEV="@comment "
.else
PLIST_SUB+=	OSSAUDIODEV=""
.endif

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	depends on Java

post-patch:
	@${MKDIR} ${WRKSRC}/jsbuildertmp && ${CP} ${DISTDIR}/JSBuilder2.zip ${WRKSRC}/jsbuildertmp
	@${REINPLACE_CMD} -e 's/ZENHOME[^.]*\.conf$$/&.example/' \
		-e 's,lib/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/GNUmakefile \
		${WRKSRC}/rrddeps.sh
	@${CP} ${FILESDIR}/libsmi-0.4.8.all.patch01 ${WRKSRC}/externallibs
	@${REINPLACE_CMD} -e '1s,#!/bin/bash,#!/usr/bin/env bash,' \
		${WRKSRC}/genpatchdeps.sh
	@${ECHO} ${ZENHOME} > ${WRKSRC}/zenhome

do-build:
	@${DO_NADA}

do-install:
# Integrated dependencies insist on using lib/pkgconfig -- instead of huge
# patches, we'll symlink it temporarily
	@${MKDIR} ${ZENHOME}/lib \
		&& ${LN} -sF ${ZENHOME}/libdata/pkgconfig \
		${ZENHOME}/lib/pkgconfig

	@cd ${WRKSRC} && ${ENV} ${BUILD_ENV} bash ./build.sh 2>/dev/null

	@${RM} ${ZENHOME}/lib/pkgconfig

	@${MKDIR} ${ZENHOME}/fonts
	${INSTALL_DATA} ${WRKDIR}/local.conf ${ZENHOME}/etc/fonts
	@${MKDIR} ${ZENHOME}/init
	${INSTALL_DATA} ${WRKSRC}/zenhome ${ZENHOME}/init
	${INSTALL_DATA} ${WRKSRC}/build-functions.sh ${ZENHOME}/init
	${INSTALL_DATA} ${WRKSRC}/install-functions.sh ${ZENHOME}/init
	${INSTALL_DATA} ${WRKSRC}/shared-functions.sh ${ZENHOME}/init
	${INSTALL_SCRIPT} ${WRKSRC}/init.sh ${ZENHOME}/init
	${INSTALL_DATA} ${WRKDIR}/profile ${ZENHOME}/.profile
	${INSTALL_DATA} ${WRKSRC}/libzenoss/Products/ZenModel/ZenossInfo.py ${ZENHOME}/Products/ZenModel

	@${FIND} ${ZENHOME} -type f -exec ${CHOWN} ${USERS}:${GROUPS} \{\} \;
	@${LN} -fs ${PREFIX}/lib/X11/fonts/Liberation ${ZENHOME}/fonts
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
