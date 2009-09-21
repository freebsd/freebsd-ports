# New ports collection makefile for:	sysutils/uif2iso
# Date created:				27 Jan 2008
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	uif2iso
PORTVERSION=	0.1.7c
CATEGORIES=	sysutils
MASTER_SITES=	http://aluigi.altervista.org/mytoolz/
DISTNAME=	${PORTNAME}

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Convert MagicISO UIF files to ISO9660

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/src

PLIST_FILES=	bin/uif2iso
PORTDOCS=	README uif2iso.txt

post-patch:
	@${REINPLACE_CMD} 's|exit(1)|exit(0)|' ${WRKSRC}/uif2iso.c
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
