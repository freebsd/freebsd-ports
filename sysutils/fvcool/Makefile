# Created by: Frerich Raabe <frerich.raabe@gmx.de>
# $FreeBSD$

PORTNAME=	fvcool
PORTVERSION=	1.0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/fvcool/
DISTNAME=	FVCool${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VCool for FreeBSD - Cooling software for AMD Athlon/Duron CPUs

ONLY_FOR_ARCHS=	i386
GNU_CONFIGURE=	yes
USE_RC_SUBR=	fvcool
SUB_FILES=	pkg-message
SUB_LIST+=	"PORTNAME=${PORTNAME}"
ALL_TARGET=	fvcool

PORTDOCS=	ReadMe ReadMe.jp ReadMe.tech_KT133
PLIST_FILES=	sbin/fvcool

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|@CC@|& ${CFLAGS}|; \
		s|-O3||g ; s| -s | |g' ${BUILD_WRKSRC}/Makefile.in

do-install: install-doc
	${INSTALL_PROGRAM} ${WRKSRC}/fvcool ${PREFIX}/sbin/fvcool

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.options.mk>

install-doc:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
