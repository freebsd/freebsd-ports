# Created by: michael@fuckner.net
# $FreeBSD$

PORTNAME=	arcconf
DISTVERSION=	v1_6_21062
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.adaptec.com/raid/storage_manager/
DISTNAME=	arcconf_${DISTVERSION}

MAINTAINER=	michael@fuckner.net
COMMENT=	Adaptec SCSI/SAS RAID administration tool

ONLY_FOR_ARCHS=	i386 amd64

USES=		zip

PERIODICSCRIPT=	410.status-aac-raid

SUB_FILES+=	${PERIODICSCRIPT}

RESTRICTED=	May not be redistributed in binary form
NO_CDROM=	May not be redistributed in binary form

.include <bsd.port.pre.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		installs incompatible binaries for FreeBSD
.endif

.if ${OSVERSION} >= 900000
DIST_OSVER=	9
.elif ${OSVERSION} >= 800000
DIST_OSVER=	8
.endif

.if ${ARCH} == amd64
DIST_EXT=	_x64
RUN_DEPENDS+=	${LOCALBASE}/lib/compat/libstdc++.so.6:${PORTSDIR}/misc/compat9x
.elif
RUN_DEPENDS+=	${LOCALBASE}/lib32/compat/libstdc++.so.6:${PORTSDIR}/misc/compat9x
.endif

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd${DIST_OSVER}${DIST_EXT}/cmdline/arcconf ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODICSCRIPT} ${STAGEDIR}${PREFIX}/etc/periodic/daily

.include <bsd.port.post.mk>
