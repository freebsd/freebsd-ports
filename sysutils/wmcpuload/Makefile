# New ports collection makefile for:	wmcpuload
# Date created:				18 Apr 2001
# Whom:					Soeren Boll Overgaard <boll@tolkien.dk>
#
# $FreeBSD$
#

PORTNAME=	wmcpuload
PORTVERSION=	0.7.1
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.sh.rim.or.jp/~ssato/src/
DISTNAME=	WMCPULoad-${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XPM=	yes

.ifndef(NOPORTDOCS)
post-install:
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 \
		${PREFIX}/share/doc/${PORTNAME}
.for file in README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif # !NOPORTDOCS

.include <bsd.port.mk>
