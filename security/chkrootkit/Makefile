PORTNAME=	chkrootkit
PORTVERSION=	0.58b
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.chkrootkit.org/pub/seg/pac/

MAINTAINER=	lacey.leanne@gmail.com
COMMENT=	Tool to locally check for signs of a rootkit
WWW=		http://www.chkrootkit.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cpe

SCRIPT_FILES=	chkrootkit
PROG_FILES=	chklastlog \
		chkwtmp \
		chkutmp \
		chkproc \
		chkdirs \
		ifpromisc \
		check_wtmpx \
		strings
ALL_TARGET=	${SCRIPT_FILES} ${PROG_FILES}

BINMODE=	0700

PLIST_FILES=	${ALL_TARGET:C,^,sbin/,}

PORTDOCS=	ACKNOWLEDGMENTS \
		COPYRIGHT \
		README \
		README.chklastlog \
		README.chkwtmp

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E "s/^(CC|CFLAGS)[^a-zA-Z]*=/\1 ?=/" \
		${WRKSRC}/Makefile

.for prog in ${PROG_FILES}
	@${REINPLACE_CMD} -E 's,\./(${prog}),${PREFIX}/sbin/\1,g' \
		${WRKSRC}/chkrootkit
.endfor

do-install:
	${INSTALL_SCRIPT}  ${SCRIPT_FILES:C,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${PROG_FILES:C,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
