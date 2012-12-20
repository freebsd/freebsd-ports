# Created by: Vaida Bogdan <vaida.bogdan@gmail.com>
# $FreeBSD$

PORTNAME=	secure_delete
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/group/thc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure data deletion toolkit

OPTIONS_DEFINE=	DOCS

CONFLICTS=	srm-[0-9]*

MAKE_JOBS_UNSAFE=yes

SUB_FILES=	pkg-message

MLINKS=		srm.1 sdel.1
MAN1=		srm.1 sfill.1 sswap.1 smem.1
PORTDOCS=	CHANGES FILES README secure_delete.doc usenix6-gutmann.doc
PLIST_FILES=	${BIN_PROGRAMS:S,^,bin/,} ${BIN_SCRIPTS:S,^,bin/,} bin/sdel

BIN_PROGRAMS=	srm sfill sswap smem
BIN_SCRIPTS=	the_cleaner.sh

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
	's|^CC=|CC?=| ; \
	s|-O2 |$$(CFLAGS) | ;\
	/strip/s|^|#|' ${WRKSRC}/Makefile

do-install:
.for i in ${BIN_PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${i}.1 ${MANPREFIX}/man/man1
.endfor
.for i in ${BIN_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

	${LN} -sf srm ${PREFIX}/bin/sdel

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
