# New ports collection makefile for:    3dm2
# Date created:         02 Sep 2002
# Whom:                 dbaker
#
# $FreeBSD$
#

PORTNAME=	3dm
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.lsi.com/DistributionSystem/AssetDocument/ \
		http://vivi.cat.pdx.edu/3dm2/

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	3ware RAID controller monitoring daemon and web server

USE_RC_SUBR=	3dm2.sh
USE_ZIP=	yes

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

.if ${OSVERSION} < 800000
PORTVERSION=	2.11.00.009
DISTFILES=	3DM2_CLI-FreeBSD-10.1.zip
BINSRC=		${WRKSRC}
.else
PORTVERSION=	2.09.01.004
DISTFILES=	3DM2_CLI-Linux-non-java-installer-9.5.3.zip
BINSRC=		${WRKSRC}/7x
.endif

.if ${ARCH} == "i386"
BINSUFFIX=	x86
.elif ${ARCH} == "amd64"
BINSUFFIX=	x86_64
.endif

HELPSRC=	${WRKSRC}/en

HELPDIR=	${PREFIX}/share/3dm2/help/en
ETCDIR=		${PREFIX}/etc/3dm2
MSGDIR=		${ETCDIR}/msg

post-extract:
	${TAR} zxf ${WRKSRC}/tdmCliBSD.tgz -C ${WRKSRC}
	${TAR} zxf ${WRKSRC}/tdm2Help.tgz -C ${WRKSRC}
	${TAR} zxf ${WRKSRC}/tdm2Msg.tgz -C ${WRKSRC}

post-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
	< ${FILESDIR}/3dm2.conf.sample > ${WRKSRC}/3dm2.conf.sample

do-install:
.for i in ${ETCDIR} ${MSGDIR} ${HELPDIR}/css ${HELPDIR}/images ${HELPDIR}/scripts
.if !exists(${i})
	${MKDIR} ${i}
.endif
.endfor

	${INSTALL_DATA} ${HELPSRC}/*.html ${HELPDIR}
	${INSTALL_DATA} ${HELPSRC}/*.gif ${HELPDIR}
	${INSTALL_DATA} ${HELPSRC}/*.jpg ${HELPDIR}
	${INSTALL_DATA} ${HELPSRC}/css/* ${HELPDIR}/css
	${INSTALL_DATA} ${HELPSRC}/images/* ${HELPDIR}/images
	${INSTALL_DATA} ${HELPSRC}/scripts/* ${HELPDIR}/scripts

	${INSTALL_PROGRAM} ${BINSRC}/3dm2.${BINSUFFIX} ${PREFIX}/sbin/3dm2

	${INSTALL_DATA} ${WRKSRC}/tdm_msg_en ${MSGDIR}
	${INSTALL_DATA} ${WRKSRC}/tw_msg_en ${MSGDIR}

	${INSTALL_DATA} ${WRKSRC}/3dm2.conf.sample ${ETCDIR}
	${CHMOD} 400 ${ETCDIR}/3dm2.conf.sample

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
