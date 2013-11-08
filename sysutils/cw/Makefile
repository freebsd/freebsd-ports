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

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.  for file in CHANGES CONTRIB FILES INSTALL PLATFORM README VERSION
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
