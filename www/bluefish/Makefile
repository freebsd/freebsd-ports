# New ports collection makefile for:   bluefish
# Version required:		0.3.2
# Date created:			25 July 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	bluefish-0.3.2
CATEGORIES=	www editors
MASTER_SITES=	http://bluefish.linuxbox.com/download/ \
		http://student.wau.nl/~olivier/bluefish/download/ \
		http://ha-pc.cheque.uq.edu.au/download/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=  yes
GNU_CONFIGURE= yes
CONFIGURE_ENV= GTK_CONFIG="${GTK_CONFIG}"

post-install:
	@strip ${PREFIX}/bin/bluefish
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing bluefish docs in ${PREFIX}/share/doc/bluefish"
	@${ECHO} "===>   A manual is available online at http://bluefish.linuxbox.com/manual/"
	@${MKDIR} ${PREFIX}/share/doc/bluefish && ${CHMOD} a+rx ${PREFIX}/share/doc/bluefish
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bluefish
.endif

.include <bsd.port.mk>
