# New ports collection makefile for:    3dm2
# Date created:         02 Sep 2002
# Whom:                 dbaker
#
# $FreeBSD$
#

PORTNAME=	3dm
PORTVERSION=	2.02.00.015
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.3ware.com/download/Escalade9000Series/9.1.5.2/
DISTNAME=	3dm-x86-bsd
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3ware RAID controller monitoring daemon and web server

USE_RC_SUBR=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 450000
IGNORE=		"3ware 3ware ATA RAID (twe) is not supported in versions earlier than 4.5-RELEASE"
.endif

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/x86

SHAREDIR=	${PREFIX}/share/3dm2/en

SED_SCRIPT=	-e 's,%%NAME%%,3dm2,g' \
		-e 's:%%PREFIX%%:${PREFIX}:g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

post-configure:
	${SED} ${SED_SCRIPT} ${FILESDIR}/3dm2.sh > ${WRKSRC}/3dm2.sh
	${SED} ${SED_SCRIPT} ${FILESDIR}/3dm2.conf.sample > ${WRKSRC}/3dm2.conf.sample

pre-install:
	@cd ${WRKSRC}; ${TAR} zxf 3dm-bsd.tgz
	@cd ${WRKSRC}; ${TAR} zxf 3dm-help.tgz

do-install:

.if !exists(${SHAREDIR}/images)
	${MKDIR} ${SHAREDIR}/images
.endif

.if !exists(${SHAREDIR}/scripts)
	${MKDIR} ${SHAREDIR}/scripts
.endif

	${INSTALL_DATA} ${WRKSRC}/en/*.html ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/en/*.css ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/en/images/* ${SHAREDIR}/images
	${INSTALL_DATA} ${WRKSRC}/en/scripts/*.js ${SHAREDIR}/scripts
	${INSTALL_PROGRAM} ${WRKSRC}/3dm2 ${PREFIX}/sbin
	${CHMOD} 500 ${PREFIX}/sbin/3dm2

.if !exists(/etc/3dm2)
	${MKDIR} /etc/3dm2
.endif

.if !exists(${PREFIX}/etc/3dm2.conf)
	@${ECHO} ""
	@${ECHO} ""
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} "           Don't forget to edit '${PREFIX}/etc/3dm2.conf'		"
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} "             Visit https://`hostname`:888/		"
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} ""
	@${ECHO} ""
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/3dm2.conf.sample ${PREFIX}/etc/
	[ -f ${PREFIX}/etc/3dm2.conf ] || \
		${CP} ${PREFIX}/etc/3dm2.conf.sample \
		${PREFIX}/etc/3dm2.conf
	${INSTALL_SCRIPT} ${WRKSRC}/3dm2.sh ${PREFIX}/etc/rc.d/
	${CHMOD} 600 ${PREFIX}/etc/3dm2.conf.sample ${PREFIX}/etc/3dm2.conf

# The binary, "3dm2" looks for the config file in /etc/3dm2, which is lame.  The file
# is placed in ${PREFIX}/etc/ (usually /usr/local/etc) and symlinked in /etc/3dm2
# so that the binary can find it.

	${LN} -s ${PREFIX}/etc/3dm2.conf /etc/3dm2/3dm2.conf
	${LN} -s ${PREFIX}/etc/3dm2.pem /etc/3dm2/3dm2.pem

	@${ECHO} ""
	@${ECHO} "Add twdm2_enable="YES" to /etc/rc.conf to run 3dm2 from startup."
	@${ECHO} ""

.include <bsd.port.post.mk>
