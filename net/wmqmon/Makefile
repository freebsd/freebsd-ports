# New ports collection makefile for:	wmqmon
# Date created:				Mon May 28 13:59:51 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmqmon
PORTVERSION=	0.7
CATEGORIES=	net windowmaker games
MASTER_SITES=	http://www.gibfest.org/~w1nter/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org

ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

do-configure:
	@${PERL} -pi -ne "s|/usr/X11R6/|${X11BASE}/|" \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${ECHO} "===>   Installing wmqmon.rcfile.example in ${PREFIX}/share/examples/${PORTNAME}"
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/wmqmon.rcfile.example ${PREFIX}/share/examples/${PORTNAME}
.ifndef(NOPORTDOCS)
	@${ECHO} "===>   Installing README in ${PREFIX}/share/doc/${PORTNAME}"
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 \
		${PREFIX}/share/doc/${PORTNAME}
.for file in BUGS README
	@${INSTALL_DATA} ${WRKSRC}/../${file} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif # !NOPORTDOCS
	@${SED} -e "s|/usr/X11R6/|${PREFIX}/|" ${PKGMESSAGE}

.include <bsd.port.mk>
