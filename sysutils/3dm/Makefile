# New ports collection makefile for:    3dm2
# Date created:         02 Sep 2002
# Whom:                 dbaker
#
# $FreeBSD$
#

PORTNAME=	3dm
PORTVERSION=	2.11.00.019
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://shibboleet.com/3dm2/ \
		http://b.aranea.brtsvcs.net/3dm2/
DISTFILES=	tdmCliBSD_${PORTVERSION}.tar.gz
DIST_SUBDIR=	3dm2

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	3ware RAID controller monitoring daemon and web server

USE_RC_SUBR=	3dm2

OPTIONS=	SSLFIX "Install KB16625-patched binaries" On

.include <bsd.port.options.mk>

.if defined(WITH_SSLFIX)
DISTFILES+=	kb16625_${PORTVERSION}.tar.gz
BINPREFIX=	${WRKSRC}/kb16625
.else
BINPREFIX=	${WRKSRC}
.endif

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

.if ${OSVERSION} > 700000
BINSRC=		${BINPREFIX}/7x
.else
BINSRC=		${BINPREFIX}/6x
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
	@${ECHO} "        Don't forget to edit '${PREFIX}/etc/3dm2/3dm2.conf'"
	@${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@${ECHO} "             Visit https://`hostname`:888/"
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
