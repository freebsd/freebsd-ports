# Created by: ijliao
# $FreeBSD$

PORTNAME=	ccrypt
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF \
		http://www.mathstat.dal.ca/~selinger/ccrypt/download/

MAINTAINER=	dev2@heesakkers.info
COMMENT=	Command-line utility for encrypting and decrypting files and streams

LICENSE=		GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=			gmake

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USES+=		gettext
.else
PLIST_SUB+=	NLS="@comment "
USES+=		perl5
USE_PERL5=	build
CONFIGURE_ARGS+=	--disable-nls
.endif

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|gtar|tar|g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.for i in ccrypt.html cypfaq01.txt
	${INSTALL_DATA} ${WRKSRC}/doc/$i ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
