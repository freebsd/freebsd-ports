# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	cw
PORTVERSION=	1.0.16
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://cwrapper.sourceforge.net/ \
		http://www.fakehalo.us/cw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Non-intrusive color wrapper for common commands

LICENSE=	GPLv2

USES=		shebangfix

SHEBANG_FILES=	def/*
SHEBANG_LANG=	cw
cw_OLD_CMD=	/cw
cw_CMD=		${PREFIX}/bin/cw

GNU_CONFIGURE=	yes
ALL_TARGET=	local

PORTDOCS=	CHANGES CONTRIB FILES INSTALL PLATFORM README VERSION

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.for file in cw cwu
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
