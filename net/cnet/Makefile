# New ports collection makefile for:    cnet
# Date created:         Feb 8th, 1988
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	cnet
PORTVERSION=	1.6
PORTREVISION=	3
CATEGORIES=	net tk82
MASTER_SITES=	http://www.cs.uwa.edu.au/cnet/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
ALL_TARGET=	# empty
MAN1=		cnet.1

post-extract:
	${CP} ${FILESDIR}/Makefile.freebsd ${WRKSRC}/src
	${CP} ${FILESDIR}/compile.c ${WRKSRC}/src/compile/freebsd.c

post-patch:
	@${PERL} -pi.in \
		-e "s|%%CC%%|${CC}|g;" \
		-e "s|%%PREFIX%%|${PREFIX}|g;" \
			${WRKSRC}/src/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cnet ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/cnet.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/DOC/cnet.man ${PREFIX}/man/man1/cnet.1
	@${MKDIR} ${PREFIX}/share/cnet
	${INSTALL_DATA} ${WRKSRC}/cnetlib/* ${PREFIX}/share/cnet
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/cnet
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES/* ${PREFIX}/share/examples/cnet
	@${MKDIR} ${PREFIX}/share/doc/cnet
	${INSTALL_DATA} ${WRKSRC}/DOC/*.html ${PREFIX}/share/doc/cnet
	@${MKDIR} ${PREFIX}/share/doc/cnet/images
	${INSTALL_DATA} ${WRKSRC}/DOC/images/* ${PREFIX}/share/doc/cnet/images
.endif

.include <bsd.port.mk>
