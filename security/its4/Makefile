# New ports collection makefile for:	its4
# Date created:				21 February 2000
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	its4
PORTVERSION=	1.1.1
CATEGORIES=	security
MASTER_SITES=
EXTRACT_SUFX=	.tgz

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Tool to scan C/C++ source for potential vulnerabilities

WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datadir=${PREFIX}/share/its4
MAN1=		its4.1

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"The source to this port may not be automatically fetched due to licensing restrictions.  You MUST fetch the source manually at: http://www.cigital.com/its4/download.html  Once ${DISTFILES} has been downloaded, move it to ${DISTDIR} and then restart this build"
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/its4
	@${ECHO}
	@${ECHO} "This software is for non-commercial use only.  See"
	@${ECHO} "${PREFIX}/share/its4/LICENSE for details."
	@${ECHO}

.include <bsd.port.post.mk>
