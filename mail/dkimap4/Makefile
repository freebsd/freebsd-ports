# New ports collection makefile for:	dkimap4
# Date created:		18 June 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	dkimap4
PORTVERSION=	2.35
CATEGORIES=	mail
MASTER_SITES=	http://www.dbox.handshake.de/download/ \
		http://www.cs.cmu.edu/~kroening/dbox/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@fix.no

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

# dkimap will look for incoming mail folders (mbox format) here instead of
# the default from paths.h (/var/mail/) if you uncomment it:
#SPOOLDIR?=	/var/mail/foo/
# dkimap message store:
DKIMAPSPOOL?=	/var/spool/dkimap/
# remember to use a slash in the end of these directories

MAKE_ARGS+=	BIN_DIR="${PREFIX}/bin" DKIMAPSPOOL="${DKIMAPSPOOL}"
.if defined(SPOOLDIR)
MAKE_ARGS+=	SPOOLDIR="${SPOOLDIR}"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/movemail/movemail ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dkimap4/dkimap4 ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/dkpop3/dkpop3 ${PREFIX}/libexec

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
