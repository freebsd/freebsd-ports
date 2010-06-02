# New ports collection makefile for:	fvcool
# Date created:				5 October 2002
# Whom:				Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	fvcool
PORTVERSION=	1.0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/fvcool/
DISTNAME=	FVCool${PORTVERSION:S/.//g}

MAINTAINER=	ports@freebsd.org
COMMENT=	VCool for FreeBSD - Cooling software for AMD Athlon/Duron CPUs

ONLY_FOR_ARCHS=	i386
GNU_CONFIGURE=	yes
USE_RC_SUBR=	fvcool.sh
SUB_FILES=	pkg-message
SUB_LIST+=	"PORTNAME=${PORTNAME}"
ALL_TARGET=	fvcool
PLIST_SUB+=	DOCSDIR=${DOCSDIR:S,^${PREFIX}/,,}

PORTDOCS=	ReadMe ReadMe.jp ReadMe.tech_KT133
PLIST_FILES=	sbin/fvcool

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
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
