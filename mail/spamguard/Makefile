# Created by: Omer Faruk Sen <ofsen@enderunix.org>
# $FreeBSD$

PORTNAME=	spamguard
PORTVERSION=	1.8
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/spamguard/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	MTA spam prevention program for qmail/postfix/sendmail

LICENSE=	BSD3CLAUSE

USE_AUTOTOOLS=	automake

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

DOCS=		AUTHORS CHANGELOG COPYING INSTALL \
		POST-INSTALL README THANKS README.DigitalUnix \
	        THANKS TODO UPGRADE
DOCS_TR=	BENIOKU BENIOKU.DigitalUnix COPYING DEGISIKLIKLER \
		GUNCELLEME KURULUM KURULUM-SONRASI YAPILACAKLAR YAZARLAR

SUB_FILES=	pkg-message

pre-configure:
	cd ${WRKSRC}; ./autogen.sh

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/tr
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/tr && ${INSTALL_DATA} ${DOCS_TR} ${STAGEDIR}${DOCSDIR}/tr

.include <bsd.port.mk>
