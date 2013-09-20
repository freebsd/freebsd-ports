# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	cpupowerd
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	decke@FreeBSD.org
COMMENT=	A CPU over- and undervolting daemon

USE_RC_SUBR=	cpupowerd
ONLY_FOR_ARCHS=	i386 amd64
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKE_ENV+=	GROUP=wheel \
		RIGHTS=555

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if (${OSVERSION} < 800042 && ${OSVERSION} >= 800000) || ${OSVERSION} < 701102
BUILD_DEPENDS+=	${LOCALBASE}/include/cpu.h:${PORTSDIR}/sysutils/devcpu
SUB_LIST+=	CPUCTL="cpu"
.else
SUB_LIST+=	CPUCTL="cpuctl"
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../CHANGELOG ${DOCSDIR}/CHANGELOG
	${INSTALL_DATA} ${WRKSRC}/../COPYING ${DOCSDIR}/COPYING
	${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/../TODO ${DOCSDIR}/TODO
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
