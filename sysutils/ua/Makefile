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
MAN1=		kua.1 ua.1

.include <bsd.port.options.mk>

post-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${MANPREFIX}/man/man1/
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
