PORTNAME=	ccrypt
DISTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${DISTVERSION}/ \
		http://www.mathstat.dal.ca/~selinger/ccrypt/download/${DISTVERSION}/

MAINTAINER=	dev2@heesakkers.info
COMMENT=	Command-line utility for encrypting and decrypting files and streams
WWW=		https://ccrypt.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README doc/ccrypt.html doc/cypfaq01.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
