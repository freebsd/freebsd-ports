# New ports collection makefile for:	husky-hpt-devel
# Date created:				2005-10-26
# Whom:					Oleg Sharoiko <os@rsu.ru>
#
# $FreeBSD$
#

PORTNAME=	hpt
DISTVERSION=	1.4-rc5
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/${PORTNAME}/1.4-RC5

MAINTAINER=	os@rsu.ru
COMMENT=	Highly Portable Tosser (full-featured FTN tosser). Development version

LIB_DEPENDS=	fidoconfig.1:${PORTSDIR}/news/husky-fidoconf-devel

CONFLICTS=	husky-hpt-[0-9]*

.if !defined(WITHOUT_PERL)
MAKE_ARGS+=	PERL=1
USE_PERL5=	yes
.else
MAKE_ARGS+=	PERL=0
.endif

MAN1=		hpt.1 hptlink.1 hpttree.1 pktinfo.1 txt2pkt.1
MANCOMPRESSED=	yes
INFO=		hpt

DOCSDIR=	${PREFIX}/share/doc/husky
PORTDOCS=	hpt.html

post-patch:
	@${REINPLACE_CMD} -e 's^/path/to/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/hptlink.1
	@${REINPLACE_CMD} -e 's^/some/path/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/hpttree.1
	@${REINPLACE_CMD} -e 's^/fido/etc/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/txt2pkt.1

post-build:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/doc && ${GMAKE} ${MAKE_ARGS} all
.endif

post-install:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/doc && ${GMAKE} ${MAKE_ARGS} install
.endif

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../news/husky-base-devel/Makefile.inc"
.include <bsd.port.post.mk>
