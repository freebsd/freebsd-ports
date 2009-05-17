# New ports collection makefile for:	qq
# Date created:		2009-04-05
# Whom:			Kai Wang <kaiw27@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qq
DISTVERSION=	v1.0.2-beta1_i386
CATEGORIES=	net-im
MASTER_SITES=	http://dl_dir.qq.com/linuxqq/
DISTNAME=	linuxqq_${DISTVERSION}

MAINTAINER=	kaiw27@gmail.com
COMMENT=	Tencent QQ for Linux

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	gtk2 xorglibs
NO_BUILD=	yes

QQDIR=		libexec/qq
PLIST_SUB+=	QQDIR=${QQDIR}
SUB_FILES=	qq.sh
SUB_LIST+=	QQDIR=${QQDIR}

.include <bsd.port.pre.mk>

pre-fetch:
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"==============================================="
	@${ECHO_MSG}    "QQ requires linux_base-f8 ports infrastructure."
	@${ECHO_MSG}	"Press 'Ctrl-C' to stop now if you dont't have  "
	@${ECHO_MSG}	"the right version installed.                   "
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"Please read ${PORTSDIR}/UPDATING for how to    "
	@${ECHO_MSG}	"install the linux_base-f8 ports.               "
	@${ECHO_MSG}	"==============================================="
	@${ECHO_MSG}	""

do-install:
	@${MKDIR} ${PREFIX}/${QQDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/qq ${PREFIX}/${QQDIR}/
	${INSTALL_DATA} ${WRKSRC}/res.db ${PREFIX}/${QQDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/qq.sh ${PREFIX}/bin/qq

.include <bsd.port.post.mk>
