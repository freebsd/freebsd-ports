# New ports collection makefile for:	fvcool
# Date created:				5 October 2002
# Whom:				Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	fvcool
PORTVERSION=	1.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/
DISTNAME=	FVCool${PORTVERSION:S/.//g}

MAINTAINER=	frerich.raabe@gmx.de

ONLY_FOR_ARCHS=	i386
USE_REINPLACE=	yes
ALL_TARGET=	fvcool
PLIST_SUB+=	DOCSDIR=${DOCSDIR:S,^${PREFIX}/,,}

DOC_FILES=	00README.txt 00READMEj.txt 00READMEkt133.txt

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC} ${CFLAGS}|; \
		s|-O3||;s|-s$$||' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install: install-doc
	@${INSTALL_PROGRAM} ${WRKSRC}/fvcool ${PREFIX}/sbin/fvcool

post-install:
	@${CAT} ${PKGMESSAGE}

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
