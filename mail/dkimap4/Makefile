# New ports collection makefile for:	dkimap4
# Date created:		18 June 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	dkimap4
PORTVERSION=	2.39
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.dbox.handshake.de/download/ \
		http://www-2.cs.cmu.edu/~kroening/dbox/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IMAP4rev1 and POP3 server from the DBOX BBS package

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

DOCS=	README

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/movemail/movemail ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dkimap4/dkimap4 ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/dkpop3/dkpop3 ${PREFIX}/libexec

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/share/doc/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
