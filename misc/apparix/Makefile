# Created by: Frank Steinborn <steinex@nognu.de>
# $FreeBSD$

PORTNAME=	apparix
PORTVERSION=	20110303
CATEGORIES=	misc
MASTER_SITES=	http://micans.org/apparix/src/
DISTNAME=	${PORTNAME}-11-062

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bookmark directories and apparate inside them

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes

MAN1=		apparix.1
PORTDOCS=	apparix.azm apparix.html apparix.ps
PLIST_FILES=	bin/apparix

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/apparix ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/apparix.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
