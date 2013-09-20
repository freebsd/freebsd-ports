# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	cw
PORTVERSION=	1.0.16
CATEGORIES=	sysutils
MASTER_SITES=	http://cwrapper.sourceforge.net/ \
		http://www.fakehalo.us/cw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Non-intrusive color wrapper for common commands

GNU_CONFIGURE=	yes

MANCOMPRESSED=	yes
MAN1=		cw.1 cwe.1 cwu.1

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.  for file in CHANGES CONTRIB FILES INSTALL PLATFORM README VERSION
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
