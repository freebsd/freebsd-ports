# New ports collection makefile for:	mmr
# Date created:				23 October 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	mmr
PORTVERSION=	1.6.0
CATEGORIES=	mail
MASTER_SITES=	http://www.sourcefiles.org/Internet/Mail/Clients/Console/ \
		http://slouken.libsdl.org/projects/mmr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses based MIME Mail Reader

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv
MAKE_ARGS=	LIBS='${LDFLAGS}' CXX='${CXX}' CXXFLAGS='${CXXFLAGS}'
ALL_TARGET=	${PORTNAME}

PORTDOCS=	BUGS CHANGES Features README TODO
PORTEXAMPLES=	dot.mmrc.sample
PLIST_FILES=	bin/mmr

CXXFLAGS+=	-DTHREADMAIL \
		-DMAILPATH=\"/var/mail\" \
		-DMAILER=\"/usr/sbin/sendmail\ -t\" \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -liconv -lcurses -lmd

post-patch:
	@${REINPLACE_CMD} -e 's|md5/libmd5.a||g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmr ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/DOT-mmrc ${EXAMPLESDIR}/dot.mmrc.sample
.endif

.include <bsd.port.mk>
