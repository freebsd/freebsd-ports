# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scanmem
PORTVERSION=	0.13
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}_

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Locate and modify a variable in an executing process

LICENSE=	GPLv3

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	requires linprocfs(5)

USES=		readline
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/scanmem man/man1/scanmem.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/proc/,/compat/linux&,' ${WRKSRC}/configure

.include <bsd.port.mk>
