# New ports collection makefile for:	gtkpasman
# Date created:				25 Aug 2004
# Whom:					Philippe Rocques
#
# $FreeBSD$
#

PORTNAME=	gtkpasman
PORTVERSION=	0.9
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-sources/${PORTVERSION}

MAINTAINER=	phil@teaser.fr
COMMENT=	A GTK+ passwords manager for system and network administrators

RUN_DEPENDS+=   gpgv:${PORTSDIR}/security/gnupg1

USE_GMAKE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:15 aclocal:15 autoconf:262

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

DOCS=		README src/gpasman4.sample
PLIST_FILES=	bin/gtkpasman
ACLOCAL_ARGS?=	--acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal

.if !defined(NOPORTDOCS)
PORTDOCS=	README gpasman4.sample
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gtkpasman ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
