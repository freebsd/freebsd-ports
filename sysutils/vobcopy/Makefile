# New ports collection makefile for:	VOB dvd rip
# Date created:				Sun May 12 09:25:37 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vobcopy
PORTVERSION=	0.5.5
CATEGORIES=	sysutils
MASTER_SITES=	http://lpn.rnbhq.org/download/

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS=	dvdread.2:${PORTSDIR}/graphics/libdvdread \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

HAS_CONFIGURE=	yes
USE_REINPLACE=	yes

ALL_TARGET=	${PORTNAME}

MAN1=	vobcopy.1

DOC_FILES=      COPYING Changelog README Release-Notes \
		FAQ TODO \
		alternative_programs.txt

post-patch:
	@${REINPLACE_CMD} -E -e 's|(fopen\("/etc/)mtab|\1fstab|; \
		s|iso9660|cd9660|' ${WRKSRC}/dvd.c

post-configure:
	@${REINPLACE_CMD} -E -e 's|^CC.+||; s|^PREFIX.+||; \
		s|/usr/local/|${LOCALBASE}/|' \
		${WRKSRC}/Makefile

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
