# New ports collection makefile for:	VOB dvd rip
# Date created:				Sun May 12 09:25:37 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vobcopy
PORTVERSION=	0.4.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lin-prog-newbie

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS=	dvdread.2:${PORTSDIR}/graphics/libdvdread

ALL_TARGET=	${PORTNAME}

MAN1=	vobcopy.1

DOC_FILES=      COPYING Changelog README Release-Notes \
		alternative_programs.txt

post-patch:
	@${PERL} -pi.orig -e 's|^CC.+||; s|^PREFIX.+||; \
		s|/usr/local/|${LOCALBASE}/|; \
		s|-D_LARGEFILE\d?\d?_SOURCE||g; \
		s|-D_FILE_OFFSET_BITS=64||' ${WRKSRC}/Makefile
	@${PERL} -pi.orig -e 's|(fopen\("/etc/)mtab|\1fstab|; \
		s|iso9660|cd9660|' ${WRKSRC}/dvd.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/vobcopy ${PREFIX}/bin/vobcopy
	@${INSTALL_MAN} ${WRKSRC}/vobcopy.1 ${MANPREFIX}/man/man1/vobcopy.1
.ifndef(PORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
