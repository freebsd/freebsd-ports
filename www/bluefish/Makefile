# New ports collection makefile for:   bluefish
# Date created:			25 July 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bluefish
PORTVERSION=	0.6
CATEGORIES=	www editors
MASTER_SITES=	http://pkedu.fbt.eitn.wau.nl/~olivier/downloads/ \
		ftp://bluefish.advancecreations.com/pub/bluefish/downloads/ \
		http://bluefish.mrball.net/downloads/ \
		ftp://ftp.ratisbona.com/pub/bluefish/downloads/ \
		http://bluefish.shellhung.org/downloads/

MAINTAINER=	jim@FreeBSD.org

RUN_DEPENDS=	weblint:${PORTSDIR}/www/weblint

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_IMLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-install-location="${X11BASE}/lib/bluefish" \
		--disable-nls

MANCOMPRESSED=	no
MAN1=		bluefish.1

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing bluefish docs in ${PREFIX}/share/doc/bluefish"
	@${ECHO} "===>   A manual is available online at http://bluefish.linuxbox.com/manual/"
	@${MKDIR} ${PREFIX}/share/doc/bluefish && ${CHMOD} a+rx ${PREFIX}/share/doc/bluefish
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bluefish
.endif

.include <bsd.port.mk>
