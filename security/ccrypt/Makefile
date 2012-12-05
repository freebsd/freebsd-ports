# Created by: ijliao
# $FreeBSD$

PORTNAME=	ccrypt
PORTVERSION=	1.10
CATEGORIES=	security
MASTER_SITES=	SF \
		http://www.mathstat.dal.ca/~selinger/ccrypt/download/

MAINTAINER=	dev2@heesakkers.info
COMMENT=	Command-line utility for encrypting and decrypting files and streams

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.else
PLIST_SUB+=	NLS="@comment "
USE_PERL5_BUILD=	yes
CONFIGURE_ARGS+=	--disable-nls
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	ccrypt.1 ccguess.1
MLINKS=	ccrypt.1 ccencrypt.1 \
	ccrypt.1 ccdecrypt.1 \
	ccrypt.1 ccat.1

post-patch:
	@${REINPLACE_CMD} -e 's|gtar|tar|g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.for i in ccrypt.html cypfaq01.txt
	${INSTALL_DATA} ${WRKSRC}/doc/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
