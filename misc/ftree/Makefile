# New ports collection makefile for:	ftree
# Date created:				20 November 2000
# Whom:					Kim Scarborough <user@unknown.nu>
#
# $FreeBSD$
#

PORTNAME=	ftree
PORTVERSION=	1.6
CATEGORIES=	misc linux
MASTER_SITES=	http://www.vjet.demon.co.uk/ftree/ \
		http://www.unknown.nu/ports/
DISTNAME=	ftree-1.6-static
EXTRACT_SUFX=	.tgz

MAINTAINER=	user@unknown.nu

RUN_DEPENDS=	/compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
NO_CDROM=	Non-commercial use only
RESTRICTED=	Non-commercial use only

WRKSRC=		${WRKDIR}/usr
MAN1=		ftree.1

STRIP=			# empty: do not strip linux binary!

do-patch:
do-configure:
do-build:
	brandelf -t Linux ${WRKSRC}/X11R6/bin/ftree
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/X11R6/bin/ftree ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/X11R6/man/man1/ftree.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ftree
	${MKDIR} ${PREFIX}/share/doc/ftree/examples
	${INSTALL_DATA} ${WRKSRC}/doc/ftree-1.6/Copyright\
	${PREFIX}/share/doc/ftree
	${INSTALL_DATA} ${WRKSRC}/doc/ftree-1.6/ReleaseNotes-1.6.txt\
	${PREFIX}/share/doc/ftree
	${INSTALL_DATA} ${WRKSRC}/doc/ftree-1.6/examples/royal.ged\
	${PREFIX}/share/doc/ftree/examples
.endif

pre-install:
	@${ECHO}
	@${ECHO} "This software is licensed for NON-COMMERCIAL USE only. If you intend"
	@${ECHO} "to use ftree for any commercial purpose you must contact the author"
	@${ECHO} "at ftree@vjet.demon.co.uk for a license arrangement."
	@${ECHO}

.include <bsd.port.mk>
