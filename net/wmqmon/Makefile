# New ports collection makefile for:	wmqmon
# Date created:				Mon May 28 13:59:51 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmqmon
PORTVERSION=	0.7
CATEGORIES=	net windowmaker games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pat
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org

ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

pre-patch:
	@${PERL} -pi -ne "s|/usr/X11R6/|${X11BASE}/|" \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/wmqmon.rcfile.example \
		${PREFIX}/share/examples/${PORTNAME}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in BUGS README
	@${INSTALL_DATA} ${WRKSRC}/../${file} ${DOCSDIR}
.endfor
.endif # !NOPORTDOCS
	@${SED} -e "s|/usr/X11R6/|${PREFIX}/|" ${PKGMESSAGE}

.include <bsd.port.mk>
