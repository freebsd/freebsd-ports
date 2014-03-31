# $FreeBSD$

PORTNAME=	ua
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Finds sets of identical files

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/kua bin/ua \
		man/man1/kua.1.gz man/man1/ua.1.gz
PORTDOCS=	README
MAN1L=		kua.1 ua.1

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OSVERSION} > 1000000
.if ${CC} != gcc42
BROKEN= needs gcc4.2 to compile
.endif
.endif

post-install:
.for i in ${MAN1L}
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/man/man1/
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
