# Created by: Kai Wang <kaiw27@gmail.com>
# $FreeBSD: head/net-im/qq/Makefile 351192 2014-04-13 09:18:40Z xmj $

PORTNAME=	qq
DISTVERSION=	v1.0.2-beta1_i386
PORTREVISION=	2
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

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${QQDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/qq ${STAGEDIR}${PREFIX}/${QQDIR}/
	${INSTALL_DATA} ${WRKSRC}/res.db ${STAGEDIR}${PREFIX}/${QQDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/qq.sh ${STAGEDIR}${PREFIX}/bin/qq

.include <bsd.port.post.mk>
