# Created by: Daniel Baker <dbaker@FreeBSD.org>
# $FreeBSD$

PORTNAME=	3dm
PORTVERSION=	2.11.00.021
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.avagotech.com/docs-and-downloads/raid-controllers/raid-controllers-common-files/
DISTNAME=	3DM2_CLI-freebsd_10-2-2-1_9-5-5-1
DIST_SUBDIR=	3dm2

MAINTAINER=	takefu@airport.fm
COMMENT=	3ware RAID controller monitoring daemon and web server

LICENSE=	3dm
LICENSE_NAME=	AVAGO
LICENSE_TEXT=	Source recipient must acknowledge license.\
		Reproduction or redistribution prohibited.\
		See http://www.avagotech.com/cs/Satellite?pagename=AVG2/Utilities/EulaMsg
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

USES=		zip
USE_RC_SUBR=	3dm2
SUB_FILES=	pkg-message 3dm2.conf.sample
ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
MSGDIR=		${ETCDIR}2/msg

post-extract:
	@${TAR} xzf ${WRKSRC}/tdmCliBSD.tgz -C${WRKSRC}
	@${TAR} xzf ${WRKSRC}/tdm2Help.tgz -C${WRKSRC}
	@${TAR} xzf ${WRKSRC}/tdm2Msg.tgz -C${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}2 ${STAGEDIR}${MSGDIR}
	@(cd ${WRKSRC}/en && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}2/help/en)
	${INSTALL_PROGRAM} ${WRKSRC}/7x/3dm2.${ARCH:S,i386,x86,:S,amd64,x86_64,} \
		${STAGEDIR}${PREFIX}/sbin/3dm2
	${INSTALL_DATA} ${WRKSRC}/tdm_msg_en ${STAGEDIR}${MSGDIR}
	${INSTALL_DATA} ${WRKSRC}/tw_msg_en ${STAGEDIR}${MSGDIR}
	${INSTALL_DATA} ${WRKDIR}/3dm2.conf.sample ${STAGEDIR}${ETCDIR}2

# 3ware uses a hardcoded config dir location that doesn't match hier(9)
	@${MKDIR} ${STAGEDIR}/etc/3dm2
	(cd ${STAGEDIR} && ${LN} -s ${PREFIX}/etc/3dm2/3dm2.conf etc/3dm2/3dm2.conf)
	(cd ${STAGEDIR} && ${LN} -s ${PREFIX}/etc/3dm2/3dm2.pem etc/3dm2/3dm2.pem)

.include <bsd.port.mk>
