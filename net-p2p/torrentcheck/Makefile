# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	torrentcheck
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} readme.txt
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${_DISTFILES:N*.txt}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Command-line torrent viewer and hash checker

LICENSE=	PD

USES=		zip
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/malloc\.h/d' ${WRKSRC}/torrentcheck.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -DUSE_FTELLO \
		-o ${PORTNAME} sha1.c torrentcheck.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
# Convert to Unix line-endings and trim useless compile-related information
	${TR} -d \\r < ${_DISTDIR}/readme.txt | ${SED} '126,$$d' > \
		${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
