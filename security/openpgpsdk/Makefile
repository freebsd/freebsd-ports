# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openpgpsdk
PORTVERSION=	0.9
CATEGORIES=	security
MASTER_SITES=	http://openpgp.nominet.org.uk/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenPGP SDK

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

BUILD_DEPENDS=	gpg2:security/gnupg
LIB_DEPENDS=	libcunit.so:devel/cunit

USES=		perl5 shebangfix tar:tgz
SHEBANG_FILES=	configure util/*.pl
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-idea --with-cunit=${LOCALBASE}

PLIST_FILES=	bin/openpgp lib/libops.a

post-patch:
	@${REINPLACE_CMD} 's|-Werror -W -g|${CFLAGS}|' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.template -exec ${REINPLACE_CMD} \
		's|-Werror -g|${CFLAGS}|; /^LDFLAGS/ s|-g|${LDFLAGS}|' {} \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/openpgp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/libops.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
