PORTNAME=	u6rd
PORTVERSION=	1.6
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://ftp.scythe.jp/pub/u6rd/release/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	User-space 6rd (RFC 5569) implementation
WWW=		http://www.scythe.jp/lab/u6rd/

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_RC_SUBR=	u6rd

PLIST_FILES=	sbin/u6rd share/man/man8/u6rd.8.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	NEWS README
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
