# Created by: Omer Faruk Sen <ofsen@enderunix.org>
# $FreeBSD$

PORTNAME=	spamguard
PORTVERSION=	1.8
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/spamguard/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MTA spam prevention program for qmail/postfix/sendmail

LICENSE=	BSD3CLAUSE

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USES=		autoreconf

OPTIONS_DEFINE=	DOCS

DOCS=		AUTHORS CHANGELOG COPYING INSTALL \
		POST-INSTALL README THANKS README.DigitalUnix \
	        THANKS TODO UPGRADE
DOCS_TR=	BENIOKU BENIOKU.DigitalUnix COPYING DEGISIKLIKLER \
		GUNCELLEME KURULUM KURULUM-SONRASI YAPILACAKLAR YAZARLAR

SUB_FILES=	pkg-message

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/tr
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/tr && ${INSTALL_DATA} ${DOCS_TR} ${STAGEDIR}${DOCSDIR}/tr

.include <bsd.port.mk>
