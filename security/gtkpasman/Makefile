# New ports collection makefile for:	gtkpasman
# Date created:				25 Aug 2004
# Whom:					Philippe Rocques
#
# $FreeBSD$
#

PORTNAME=	gtkpasman
PORTVERSION=	0.6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	phil@teaser.fr
COMMENT=	A GTK+ passwords manager for system and network administrators

DOCS=		README src/gpasman4.sample

RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
BUILD_DEPENDS+=	gdk-pixbuf-config:${PORTSDIR}/graphics/gdk-pixbuf

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_FILES=	bin/gtkpasman
.if !defined(NOPORTDOCS)
PORTDOCS=	README gpasman4.sample
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gtkpasman ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.for text in pkg-message
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
	${PKGDIR}/${text} >${WRKDIR}/${text}
.endfor

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
