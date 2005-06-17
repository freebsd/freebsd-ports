# New ports collection makefile for:	ftree
# Date created:				20 November 2000
# Whom:					Kim Scarborough <user@unknown.nu>
#
# $FreeBSD$
#

PORTNAME=	ftree
PORTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	misc linux
MASTER_SITES=	http://www.vjet.demon.co.uk/ftree/ \
		http://www.unknown.nu/ports/
DISTNAME=	${PORTNAME}-${PORTVERSION}-static
EXTRACT_SUFX=	.tgz

MAINTAINER=	user@unknown.nu
COMMENT=	An X11 genealogy program

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_CDROM=	Non-commercial use only
RESTRICTED=	Non-commercial use only

WRKSRC=		${WRKDIR}/usr
MAN1=		ftree.1

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/bin/ftree

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ftree ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/ftree.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/examples
	${INSTALL_DATA} ${WRKSRC}/share/doc/ftree-${PORTVERSION}/Copyright ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/share/doc/ftree-${PORTVERSION}/ReleaseNotes-${PORTVERSION}.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/share/doc/ftree-${PORTVERSION}/examples/royal.ged ${DOCSDIR}/examples
.endif

pre-install:
	@${ECHO}
	@${ECHO} "This software is licensed for NON-COMMERCIAL USE only. If you intend"
	@${ECHO} "to use ftree for any commercial purpose you must contact the author"
	@${ECHO} "at ftree@vjet.demon.co.uk for a license arrangement."
	@${ECHO}

.include <bsd.port.mk>
