# New ports collection makefile for:    3dmd
# Date created:         02 Sep 2002
# Whom:                 dbaker
#
# $FreeBSD$
#

PORTNAME=	3dm
PORTVERSION=	1.10.0.011
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.procplace.com/pub/contrib/3ware/3dm/ \
		http://people.freebsd.org/~msmith/RAID/3ware/
DISTNAME=	3dm-bsd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3ware ATA RAID monitoring daemon and web server

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 450000
IGNORE=		"3ware 3ware ATA RAID (twe) is not supported in versions earlier than 4.5-RELEASE"
.endif

ONLY_FOR_ARCHS=	i386
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

BINDIR=		${PREFIX}/3dm
SHAREDIR=	${PREFIX}/share/3dm

SBINMODE=	700
BINMODE=	700

pre-install:
	@cd ${WRKDIR}; ${TAR} zxf 3dm-help.tgz

do-install:

.if !exists(${SHAREDIR}/images)
	${MKDIR} ${SHAREDIR}/images
.endif

.if !exists(${SHAREDIR}/styles)
	${MKDIR} ${SHAREDIR}/styles
.endif

	${INSTALL_DATA} ${WRKSRC}/3dm/*.html ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/3dm/images/*.gif ${SHAREDIR}/images
	${INSTALL_DATA} ${WRKSRC}/3dm/styles/*.css ${SHAREDIR}/styles

	${INSTALL_PROGRAM} ${WRKSRC}/3dmd ${PREFIX}/sbin

.if !exists(${PREFIX}/etc/3dmd.conf)
	@${ECHO} ""
	@${ECHO} ""
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} "           Don't forget to edit '${PREFIX}/etc/3dmd.conf'		"
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} "             Visit http://`hostname`:1080/		"
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} ""
	@${ECHO} ""

	${INSTALL_DATA} ${FILESDIR}/3dmd.conf ${PREFIX}/etc/
#
# The binary, "3dmd" looks for the config file in etc, which is lame.  The file
# is placed in ${PREFIX}/etc/ (usually /usr/local/etc/) and symlinked in /etc/
# so that the binary can find it.
#
	${LN} -s ${PREFIX}/etc/3dmd.conf /etc/3dmd.conf
.endif

	${INSTALL_SCRIPT} -m 750 ${FILESDIR}/3dmd.sh ${PREFIX}/etc/rc.d/3dmd.sh

.include <bsd.port.post.mk>
