# New ports collection makefile for:    3dm2
# Date created:         02 Sep 2002
# Whom:                 dbaker
#
# $FreeBSD$
#

PORTNAME=	3dm
PORTVERSION=	2.09.01.004
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://vivi.cat.pdx.edu/3dm2/

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	3ware RAID controller monitoring daemon and web server

USE_RC_SUBR=	3dm2.sh
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

DISTFILES=	3dm2_${PORTVERSION}_${ARCH}.tar.bz2

.if ${OSVERSION} >= 800000
BROKEN=Requires KSE support for static-linked binaries.
.endif

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

OPTSRC=		${WRKSRC}/opt/AMCC/3DM2
HELPSRC=	${OPTSRC}/help/en
MSGSRC=		${OPTSRC}/msg

HELPDIR=	${PREFIX}/share/3dm2/help/en
MSGDIR=		${PREFIX}/etc/3dm2/msg

post-patch:
	@${REINPLACE_CMD} -e 's|AMCC-logo\.jpg|AMCC-logo-smaler\.jpg|g' \
	${WRKSRC}/opt/AMCC/3DM2/help/en/*.html

post-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
	< ${FILESDIR}/3dm2.conf.sample > ${WRKSRC}/3dm2.conf.sample

do-install:
.if !exists(${HELPDIR}/css)
	@${MKDIR} ${HELPDIR}/css
.endif

.if !exists(${HELPDIR}/images)
	@${MKDIR} ${HELPDIR}/images
.endif

.if !exists(${HELPDIR}/scripts)
	@${MKDIR} ${HELPDIR}/scripts
.endif

	${INSTALL_DATA} ${HELPSRC}/*.html ${HELPDIR}
	${INSTALL_DATA} ${HELPSRC}/*.gif ${HELPDIR}
	${INSTALL_DATA} ${HELPSRC}/*.jpg ${HELPDIR}
	${INSTALL_DATA} ${HELPSRC}/css/* ${HELPDIR}/css
	${INSTALL_DATA} ${HELPSRC}/images/* ${HELPDIR}/images
	${INSTALL_DATA} ${HELPSRC}/scripts/* ${HELPDIR}/scripts

	${INSTALL_PROGRAM} ${WRKSRC}/usr/sbin/3dm2 ${PREFIX}/sbin/3dm2

.if !exists(${PREFIX}/etc/3dm2)
	@${MKDIR} ${PREFIX}/etc/3dm2
.endif

.if !exists(${MSGDIR})
	@${MKDIR} ${MSGDIR}
.endif

	${INSTALL_DATA} ${MSGSRC}/tdm_msg_en ${MSGDIR}
	${INSTALL_DATA} ${MSGSRC}/tw_msg_en ${MSGDIR}

	${INSTALL_DATA} ${WRKSRC}/3dm2.conf.sample ${PREFIX}/etc/3dm2/
	${CHMOD} 400 ${PREFIX}/etc/3dm2/3dm2.conf.sample

post-install:
.if !exists(${PREFIX}/etc/3dm2/3dm2.conf)
	${INSTALL_DATA} ${WRKSRC}/3dm2.conf.sample ${PREFIX}/etc/3dm2/3dm2.conf
	${CHMOD} 600 ${PREFIX}/etc/3dm2/3dm2.conf
	@${ECHO} ""
	@${ECHO} ""
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} "        Don't forget to edit '${PREFIX}/etc/3dm2/3dm2.conf'		"
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} "             Visit https://`hostname`:888/		"
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} ""
	@${ECHO} ""
.endif

# 3ware uses a hardcoded config dir location that doesn't match hier(9)

.if !exists(/etc/3dm2)
	@${MKDIR} /etc/3dm2
.endif
	@${LN} -s ${PREFIX}/etc/3dm2/3dm2.conf /etc/3dm2/3dm2.conf
	@${LN} -s ${PREFIX}/etc/3dm2/3dm2.pem /etc/3dm2/3dm2.pem

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
