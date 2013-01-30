# $FreeBSD$

PORTNAME=	u6rd
PORTVERSION=	1.5
#PORTREVISION=	0
CATEGORIES=	net ipv6
MASTER_SITES=	http://ftp.scythe.jp/pub/u6rd/release/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	User-space 6rd (RFC 5569) implementation

LICENSE=	BSD

GNU_CONFIGURE=	yes
USE_RC_SUBR=	u6rd

MAN8=		u6rd.8

PLIST_FILES=	sbin/u6rd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	NEWS README
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
