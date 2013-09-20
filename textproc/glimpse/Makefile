# Created by: chuckr@FreeBSD.org
# $FreeBSD$

PORTNAME=	glimpse
PORTVERSION=	4.13.1
CATEGORIES=	textproc databases
MASTER_SITES=	LOCAL/beech

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text search engine

MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	README COPYRIGHT

NO_CDROM=	Restrictive copyright (don not sell for profit)
GNU_CONFIGURE=	yes
CFLAGS+=	-DISO_CHAR_SET=1 -D__STRICT_ANSI__
MAN1=		glimpse.1 glimpseindex.1 glimpseserver.1 agrep.1

NO_STAGE=	yes
pre-configure:
	@${CHMOD} a+x ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/index/wgconvert ${PREFIX}/bin

.include <bsd.port.mk>
