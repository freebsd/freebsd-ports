# New ports collection makefile for:    3dm2
# Date created:         02 Sep 2002
# Whom:                 dbaker
#
# $FreeBSD$
#

PORTNAME=	3dm
PORTVERSION=	2.04.00.035
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://3ware.com/download/Escalade9650SE-Series/9.4.0.1/
DISTNAME=	3DM2-freebsd-9.4.0.1
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	3ware RAID controller monitoring daemon and web server

USE_RC_SUBR=	3dm2.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 504000
IGNORE=		is not supported in versions earlier than 5.4-RELEASE
.endif

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

SHAREDIR=	${PREFIX}/share/3dm2/en

post-extract:
	@cd ${WRKSRC}; ${TAR} zxf 3dm-bsd.tgz
	@cd ${WRKSRC}; ${TAR} zxf 3dm-help.tgz
	@cd ${WRKSRC}; ${TAR} zxf 3dm-msg.tgz

post-patch:
	@${REINPLACE_CMD} -e 's|AMCC-logo\.jpg|AMCC-logo-smaler\.jpg|g' ${WRKSRC}/en/*.html

post-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
	< ${FILESDIR}/3dm2.conf.sample > ${WRKSRC}/3dm2.conf.sample

do-install:

.if !exists(${SHAREDIR}/css)
	@${MKDIR} ${SHAREDIR}/css
.endif

.if !exists(${SHAREDIR}/images)
	@${MKDIR} ${SHAREDIR}/images
.endif

.if !exists(${SHAREDIR}/scripts)
	@${MKDIR} ${SHAREDIR}/scripts
.endif

	${INSTALL_DATA} ${WRKSRC}/en/*.html ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/en/*.gif ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/en/*.jpg ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/en/css/* ${SHAREDIR}/css
	${INSTALL_DATA} ${WRKSRC}/en/images/* ${SHAREDIR}/images
	${INSTALL_DATA} ${WRKSRC}/en/scripts/* ${SHAREDIR}/scripts

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
	${INSTALL_PROGRAM} ${WRKSRC}/3dm2.x86_64 ${PREFIX}/sbin/3dm2
.else
	${INSTALL_PROGRAM} ${WRKSRC}/3dm2.x86 ${PREFIX}/sbin/3dm2
.endif

	@${CHMOD} 500 ${PREFIX}/sbin/3dm2

.if !exists(${PREFIX}/etc/3dm2)
	@${MKDIR} ${PREFIX}/etc/3dm2
.endif

.if !exists(${PREFIX}/etc/3dm2/msg)
	@${MKDIR} ${PREFIX}/etc/3dm2/msg
.endif

	${INSTALL_DATA} ${WRKSRC}/tdm_msg_en ${PREFIX}/etc/3dm2/msg
	${INSTALL_DATA} ${WRKSRC}/tw_msg_en ${PREFIX}/etc/3dm2/msg

.if !exists(${PREFIX}/etc/3dm2/3dm2.conf)
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

post-install:
	${INSTALL_DATA} ${WRKSRC}/3dm2.conf.sample ${PREFIX}/etc/3dm2/
	[ -f ${PREFIX}/etc/3dm2/3dm2.conf ] || \
		${CP} ${PREFIX}/etc/3dm2/3dm2.conf.sample \
		${PREFIX}/etc/3dm2/3dm2.conf
	@${CHMOD} 600 ${PREFIX}/etc/3dm2/3dm2.conf.sample ${PREFIX}/etc/3dm2/3dm2.conf

# 3ware uses a hardcoded config dir location that doesn't match hier(9)

.if !exists(/etc/3dm2)
	@${MKDIR} /etc/3dm2
.endif
	@${LN} -s ${PREFIX}/etc/3dm2/msg /etc/3dm2/msg
	@${LN} -s ${PREFIX}/etc/3dm2/3dm2.conf /etc/3dm2/3dm2.conf
	@${LN} -s ${PREFIX}/etc/3dm2/3dm2.pem /etc/3dm2/3dm2.pem

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
