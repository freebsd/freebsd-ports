# New ports collection makefile for:	fvcool
# Date created:				5 October 2002
# Whom:				Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	fvcool
PORTVERSION=	1.0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/
DISTNAME=	FVCool${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VCool for FreeBSD - Cooling software for AMD Athlon/Duron CPUs

ONLY_FOR_ARCHS=	i386
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	fvcool
PLIST_SUB+=	DOCSDIR=${DOCSDIR:S,^${PREFIX}/,,}

DOC_FILES=	00README.txt 00READMEj.txt 00READMEkt133.txt

post-patch:
	@${REINPLACE_CMD} -e 's|@CC@|& ${CFLAGS}|; \
		s|-O3||g ; s| -s | |g' ${BUILD_WRKSRC}/Makefile.in

do-install: install-doc
	${INSTALL_PROGRAM} ${WRKSRC}/fvcool ${PREFIX}/sbin/fvcool

post-install:
	@${CAT} ${PKGMESSAGE}

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
