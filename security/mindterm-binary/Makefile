# New ports collection makefile for:	mindterm-binary
# Date created:				22 Sep 2000
# Whom:					alex@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	mindterm-binary
PORTVERSION=	1.2.1
CATEGORIES=	security
MASTER_SITES=	http://www.mindbright.se/mindterm/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alex
DISTNAME=	mindtermbin-v121
DISTFILES=	mindterm-ssh.html ${EXTRACT_ONLY}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alex@FreeBSD.org

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

post-extract:
	@${CP} ${DISTDIR}/mindterm-ssh.html ${WRKSRC}
	@${MV} ${WRKSRC}/mindtermfull.jar ${WRKSRC}/mindterm.jar

do-install:
	@${MKDIR} ${PREFIX}/share/java/mindterm
	@${INSTALL_DATA} ${WRKSRC}/* ${PREFIX}/share/java/mindterm/

.include <bsd.port.mk>
