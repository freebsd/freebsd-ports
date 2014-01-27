# Created by: chuckr@FreeBSD.org
# $FreeBSD$

PORTNAME=	glimpse
PORTVERSION=	4.13.1
CATEGORIES=	textproc databases
MASTER_SITES=	LOCAL/beech

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text search engine

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README COPYRIGHT

USES=	desthack
NO_CDROM=	Restrictive copyright (don not sell for profit)
GNU_CONFIGURE=	yes
CFLAGS+=	-DISO_CHAR_SET=1 -D__STRICT_ANSI__

pre-configure:
	@${CHMOD} a+x ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/index/wgconvert ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
