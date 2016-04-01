# Created by: Michael Ranner <michael@ranner.eu>
# $FreeBSD$

PORTNAME=	iXhash
PORTVERSION=	1.5.5
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF/ixhash/${PORTNAME}/${PORTNAME}-${PORTVERSION}/
PKGNAMEPREFIX=	spamass-
EXTRACT_SUFX=	.tgz

MAINTAINER=	michael@ranner.eu
COMMENT=	Plugin for SpamAssassin supporting iXhash

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	spamc:mail/spamassassin \
		p5-Digest-MD5>=0:security/p5-Digest-MD5 \
		p5-Net-DNS>=0.63:dns/p5-Net-DNS

OPTIONS_DEFINE=	DOCS
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,/etc/mail,${LOCALBASE}/etc/mail," \
		${WRKSRC}/iXhash/iXhash.cf

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail/spamassassin
	${INSTALL_DATA} ${WRKSRC}/iXhash/iXhash.cf ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/iXhash.cf.sample
	${INSTALL_DATA} ${WRKSRC}/iXhash/iXhash.pm ${STAGEDIR}${PREFIX}/etc/mail/spamassassin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in CHANGELOG LICENSE WHERE_ARE_THE_OTHER_FILES INSTALL README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
