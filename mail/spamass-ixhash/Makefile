PORTNAME=	iXhash
PORTVERSION=	1.5.5
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF/ixhash/${PORTNAME}/${PORTNAME}-${PORTVERSION}/
PKGNAMEPREFIX=	spamass-

MAINTAINER=	michael@ranner.eu
COMMENT=	Plugin for SpamAssassin supporting iXhash

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	spamc:mail/spamassassin \
		p5-Net-DNS>=0.63:dns/p5-Net-DNS

OPTIONS_DEFINE=	DOCS
NO_ARCH=	yes
NO_BUILD=	yes
USES=		tar:tgz

post-patch:
	@${REINPLACE_CMD} -e "s,/etc/mail,${LOCALBASE}/etc/mail," \
		${WRKSRC}/iXhash/iXhash.cf

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail/spamassassin
	${INSTALL_DATA} ${WRKSRC}/iXhash/iXhash.cf ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/iXhash.cf.sample
	${INSTALL_DATA} ${WRKSRC}/iXhash/iXhash.pm ${STAGEDIR}${PREFIX}/etc/mail/spamassassin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in CHANGELOG LICENSE WHERE_ARE_THE_OTHER_FILES INSTALL README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
