# New ports collection makefile for:    passivetex
# Date created:         9 May 2002
# Whom:                 Nik Clayton <nik@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		passivetex
PORTVERSION=		1.17
CATEGORIES=		print
MASTER_SITES=		http://www.tei-c.org.uk/Software/passivetex/
DISTFILES=		passivetex.zip

MAINTAINER=		nik@FreeBSD.org

BUILD_DEPENDS=		${LOCALBASE}/share/texmf/web2c/xmltex.fmt:${PORTSDIR}/print/xmltex

DIST_SUBDIR=		passivetex
NO_BUILD=		yes
USE_ZIP=		yes

WRKSRC=			${WRKDIR}/passivetex

MAKE_ENV=		TEXMFCNF=${FILESDIR}:${LOCALBASE}/share/texmf/web2c

MESSAGE=		${PKGDIR}/pkg-message
PKGMESSAGE=		${WRKDIR}/pkg-message

post-patch:
	@${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${MESSAGE} > ${PKGMESSAGE}

do-install:
	@cd ${WRKSRC}; TEXMFMAIN=$$(kpsewhich -expand-var '$$TEXMFMAIN'); \
	 ${MKDIR} -m 555 $$TEXMFMAIN/tex/passivetex; \
	 ${INSTALL_DATA} dummyels.sty fotex.xmt fotex.sty mlnames.sty ucharacters.sty unicode.sty $$TEXMFMAIN/tex/passivetex;

post-install: rebuild-tex-database display-message

rebuild-tex-database:
	${LOCALBASE}/bin/mktexlsr

display-message:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
