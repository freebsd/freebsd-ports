# Created by: Luiz Eduardo R. Cordeiro
# $FreeBSD$

PORTNAME=	chkrootkit
PORTVERSION=	0.51
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.pangeia.com.br/pub/seg/pac/ \
		ftp://gd.tuwien.ac.at/infosys/security/chkrootkit/ \
		ftp://ftp.digitalvoodoo.org/pub/mirrors/chkrootkit/ \
		http://www.spenneberg.org/chkrootkit-mirror/files/ \
		http://www.mirrors.wiretapped.net/security/host-security/chkrootkit/ \
		http://ftp.uni-stuttgart.de/pub/security/unix/forensics/chkrootkit/ \
		http://ftp.bit.nl/mirror/chkrootkit/ \
		http://chkrootkit.mirror.fr/

MAINTAINER=	lacey.leanne@gmail.com
COMMENT=	Tool to locally check for signs of a rootkit

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	DOCS

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
PORTDOCS=	ACKNOWLEDGMENTS \
		COPYRIGHT \
		README \
		README.chklastlog \
		README.chkwtmp

PLIST_FILES=	${ALL_TARGET:C,^,sbin/,}

BINMODE=	0700

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
