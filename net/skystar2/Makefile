# New ports collection makefile for:	SkyStar2
# Date created:		15 November 2007
# Whom:			Alex Keda <admin@lissyara.su>
#
# $FreeBSD$
#

PORTNAME=	skystar2
PORTVERSION=	1.31
PORTEPOCH=	1
CATEGORIES=	net kld
MASTER_SITES=	http://paradox.lissyara.su/ \
		http://lissyara.su/patch/skystar2/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//}

MAINTAINER=	admin@lissyara.su
COMMENT=	Kernel module and program for SkyStar2, ver. ${PORTVERSION}

USE_BZIP2=	yes
SYSDIR?=	${SRC_BASE}/sys
KMODDIR=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}
PORTDOCS=	readme

pre-fetch:
.if !exists(${SYSDIR}/Makefile)
	@${ECHO} "*************************************************"; \
	${ECHO}  "This port requires the kernel source be available"; \
	${ECHO}  "*************************************************"; \
	exit 1
.endif

pre-install:
	${INSTALL} -d ${KMODDIR}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/etc/channels.conf.dist ${PREFIX}/etc/
	@${CAT} ${PKGMESSAGE}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
