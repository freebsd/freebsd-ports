# Created by: Daniel Baker <dbaker@FreeBSD.org>
# $FreeBSD$

PORTNAME=	3dm
PORTVERSION=	2.11.00.021
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.lsi.com/downloads/Public/SATA/SATA%20Common%20Files/3DM2_CLI-freebsd_10.2.2.1_9.5.5.1.zip?source=1/
DISTFILES=	3DM2_CLI-freebsd_10.2.2.1_9.5.5.1.zip
DIST_SUBDIR=	3dm2

MAINTAINER=	takefu@airport.fm
COMMENT=	3ware RAID controller monitoring daemon and web server

RESTRICTED=	Source recipient must acknowledge license. Reproduction or redistribution prohibited. See http://www.lsi.com/Pages/user/eula.aspx

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}

USE_RC_SUBR=	3dm2
SUB_FILES=	pkg-message 3dm2.conf.sample
SUB_LIST=	HOSTNAME=`hostname`
ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
BINSRC=		${WRKSRC}/7x
HELPSRC=	${WRKSRC}/en
HELPDIR=	${DATADIR}2/help/en
MSGDIR=		${ETCDIR}2/msg

post-extract:
	@${TAR} -xzf ${WRKSRC}/tdmCliBSD.tgz -C ${WRKSRC}
	@${TAR} -xzf ${WRKSRC}/tdm2Help.tgz -C ${WRKSRC}
	@${TAR} -xzf ${WRKSRC}/tdm2Msg.tgz -C ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}2 ${STAGEDIR}${MSGDIR}
	@cd ${HELPSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${HELPDIR}
	${INSTALL_PROGRAM} ${BINSRC}/3dm2.${ARCH:S,i386,x86,:S,amd64,x86_64,} \
		${STAGEDIR}${PREFIX}/sbin/3dm2
	${INSTALL_DATA} ${WRKSRC}/tdm_msg_en ${STAGEDIR}${MSGDIR}
	${INSTALL_DATA} ${WRKSRC}/tw_msg_en ${STAGEDIR}${MSGDIR}
	${INSTALL_DATA} ${WRKSRC}/3dm2.conf.sample ${STAGEDIR}${ETCDIR}2

# 3ware uses a hardcoded config dir location that doesn't match hier(9)

	@${MKDIR} ${STAGEDIR}/etc/3dm2
	(cd ${STAGEDIR} && ${LN} -s ${PREFIX}/etc/3dm2/3dm2.conf etc/3dm2/3dm2.conf)
	(cd ${STAGEDIR} && ${LN} -s ${PREFIX}/etc/3dm2/3dm2.pem etc/3dm2/3dm2.pem)

.include <bsd.port.mk>
