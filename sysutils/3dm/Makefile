# Created by: Daniel Baker <dbaker@FreeBSD.org>
# $FreeBSD$

PORTNAME=	3dm
PORTVERSION=	2.11.00.019
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://a.aranea.brtsvcs.net/3dm2/ \
		http://b.aranea.brtsvcs.net/3dm2/
DISTFILES=	tdmCliBSD_${PORTVERSION}.tar.gz
DIST_SUBDIR=	3dm2

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	3ware RAID controller monitoring daemon and web server

USE_RC_SUBR=	3dm2

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	SSLFIX
SSLFIX_DESC=	Install KB16625-patched binaries
OPTIONS_DEFAULT=	SSLFIX

.include <bsd.port.options.mk>

.if !empty(PORT_OPTIONS:MSSLFIX)
DISTFILES+=	kb16625_${PORTVERSION}.tar.gz
BINPREFIX=	${WRKSRC}/kb16625
.else
BINPREFIX=	${WRKSRC}
.endif

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

BINSRC=		${BINPREFIX}/7x
HELPSRC=	${WRKSRC}/en
HELPDIR=	${PREFIX}/share/3dm2/help/en
ETCDIR=		${PREFIX}/etc/3dm2
MSGDIR=		${ETCDIR}/msg

post-extract:
	@${TAR} zxf ${WRKSRC}/tdm2Help.tgz -C ${WRKSRC}
	@${TAR} zxf ${WRKSRC}/tdm2Msg.tgz -C ${WRKSRC}

post-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
	< ${FILESDIR}/3dm2.conf.sample > ${WRKSRC}/3dm2.conf.sample

do-install:
.for i in ${ETCDIR} ${MSGDIR} ${HELPDIR} \
    ${HELPDIR}/css ${HELPDIR}/images ${HELPDIR}/scripts
	${MKDIR} ${STAGEDIR}${PREFIX}${i}
	# XXX rene not sure why ${PREFIX} is ommitted from ${i} here
.endfor
	${INSTALL_DATA} ${HELPSRC}/*.html ${STAGEDIR}${HELPDIR}
	${INSTALL_DATA} ${HELPSRC}/*.gif ${STAGEDIR}${HELPDIR}
	${INSTALL_DATA} ${HELPSRC}/*.jpg ${STAGEDIR}${HELPDIR}
	${INSTALL_DATA} ${HELPSRC}/css/* ${STAGEDIR}${HELPDIR}/css
	${INSTALL_DATA} ${HELPSRC}/images/* ${STAGEDIR}${HELPDIR}/images
	${INSTALL_DATA} ${HELPSRC}/scripts/* ${STAGEDIR}${HELPDIR}/scripts

	${INSTALL_PROGRAM} ${BINSRC}/3dm2.${ARCH:S,i386,x86,:S,amd64,x86_64,}\
		${STAGEDIR}${PREFIX}/sbin/3dm2

	${INSTALL_DATA} ${WRKSRC}/tdm_msg_en ${STAGEDIR}${MSGDIR}
	${INSTALL_DATA} ${WRKSRC}/tw_msg_en ${STAGEDIR}${MSGDIR}
	${INSTALL_DATA} ${WRKSRC}/3dm2.conf.sample ${STAGEDIR}${ETCDIR}

# 3ware uses a hardcoded config dir location that doesn't match hier(9)

	${MKDIR} ${STAGEDIR}/etc/3dm2
	(cd ${STAGEDIR} && ${LN} -s ${PREFIX}/etc/3dm2/3dm2.conf etc/3dm2/3dm2.conf)
	(cd ${STAGEDIR} && ${LN} -s ${PREFIX}/etc/3dm2/3dm2.pem etc/3dm2/3dm2.pem)

.include <bsd.port.mk>
