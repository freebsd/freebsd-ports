# Created by: Omer Faruk Sen <ofsen@enderunix.org>
# $FreeBSD$

PORTNAME=	spamguard
PORTVERSION=	1.8
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/spamguard/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	MTA spam prevention program for qmail/postfix/sendmail

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake

PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes

DOCS=		AUTHORS CHANGELOG COPYING INSTALL \
		POST-INSTALL README THANKS README.DigitalUnix \
	        THANKS TODO UPGRADE
DOCS_TR=	BENIOKU BENIOKU.DigitalUnix COPYING DEGISIKLIKLER \
		GUNCELLEME KURULUM KURULUM-SONRASI YAPILACAKLAR YAZARLAR

SUB_FILES=	pkg-message

NO_STAGE=	yes
pre-configure:
	        cd ${WRKSRC}; \
		./autogen.sh

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/tr
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	cd ${WRKSRC}/tr && ${INSTALL_DATA} ${DOCS_TR} ${DOCSDIR}/tr
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
