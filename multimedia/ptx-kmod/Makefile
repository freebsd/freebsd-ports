# $FreeBSD$

PORTNAME=	ptx
PORTVERSION=	0.0.20111212
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	hrs
PKGNAMESUFFIX=	-kmod
DISTNAME=	${PORTNAME}-${PORTVERSION:S,0.0.,,}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Device driver for PT1/PT2 ISDB-S/T tuner cards

LICENSE=	GPLv3

#XXX rene: change KMODDIR from ${PREFIX}/libexec/${PORTNAME} to
#          the default /boot/modules to get directories right

ONLY_FOR_ARCHS=	amd64 i386
BUILD_WRKSRC=	${WRKSRC}/dev/ptx
PLIST_FILES=	${KMODDIR}/ptx.ko bin/recptx.pl
SUB_LIST=	KMODDIR=${KMODDIR}
USE_RC_SUBR=	ptx
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes

USES=		kmod
.include <bsd.port.pre.mk>

do-install:
	${INSTALL_KLD} ${BUILD_WRKSRC}/ptx.ko ${KMODDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/recptx.pl ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
