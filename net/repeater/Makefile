# New ports collection makefile for:	repeater
# Date created:				14 December 2005
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	repeater
PORTVERSION=	0.08
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://koti.mbnet.fi/jtko/uvncrepeater/
DISTNAME=	repeater${PORTVERSION:C/\.//}

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	UltraVNC repeater

USE_ZIP=	yes
USE_RC_SUBR=	yes
WRKSRC=		${WRKDIR}/Ver${PORTVERSION:C/\.//}
ALL_TARGET=	repeater

PLIST_FILES=	sbin/repeater etc/rc.d/repeater.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/repeater ${PREFIX}/sbin/repeater
	${INSTALL_SCRIPT} ${FILESDIR}/repeater.sh ${PREFIX}/etc/rc.d

.if !defined(NOPORTDOCS)
PORTDOCS=	changelog.txt readme.txt ultravncrepeaterlinuxport.html

post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's,%%LIMITS_H%%,machine/limits.h,g' ${WRKSRC}/repeater.cpp
.else
	@${REINPLACE_CMD} -e 's,%%LIMITS_H%%,sys/limits.h,g' ${WRKSRC}/repeater.cpp
.endif

.include <bsd.port.post.mk>
