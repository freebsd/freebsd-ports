# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	mmr
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.sourcefiles.org/Internet/Mail/Clients/Console/ \
		http://slouken.libsdl.org/projects/mmr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses based MIME Mail Reader

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv ncurses
MAKE_ARGS=	LIBS='${LIBS}' CXX='${CXX}' CXXFLAGS='${CXXFLAGS}'
ALL_TARGET=	${PORTNAME}

PORTDOCS=	BUGS CHANGES Features README TODO
PORTEXAMPLES=	dot.mmrc.sample
PLIST_FILES=	bin/mmr

CXXFLAGS+=	-DTHREADMAIL \
		-DMAILPATH=\"/var/mail\" \
		-DMAILER=\"/usr/sbin/sendmail\ -t\" \
		-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib ${ICONV_LIB} -lncurses -lmd

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|md5/libmd5.a||g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmr ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/DOT-mmrc \
		${STAGEDIR}${EXAMPLESDIR}/dot.mmrc.sample

.include <bsd.port.mk>
