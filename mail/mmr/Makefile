# New ports collection makefile for:	mmr
# Date created:				23 October 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	mmr
PORTVERSION=	1.6.0
CATEGORIES=	mail
MASTER_SITES=	http://www.devolution.com/~slouken/projects/mmr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses based MIME Mail Reader

USE_ICONV=	yes
MAKE_ARGS=	LIBS='${LDFLAGS}' CXX='${CXX}' CXXFLAGS='${CXXFLAGS}'
ALL_TARGET=	${PORTNAME}

PORTDOCS=	BUGS CHANGES Features README TODO
PLIST_FILES=	bin/mmr %%EXAMPLESDIR%%/dot.mmrc.sample
PLIST_DIRS=	%%EXAMPLESDIR%%

CXXFLAGS+=	-DTHREADMAIL \
		-DMAILPATH=\"/var/mail\" \
		-DMAILER=\"/usr/sbin/sendmail\ -t\" \
		-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -liconv -lcurses -lmd

post-patch:
	@${REINPLACE_CMD} -e 's|md5/libmd5.a||g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmr ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/DOT-mmrc ${EXAMPLESDIR}/dot.mmrc.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
