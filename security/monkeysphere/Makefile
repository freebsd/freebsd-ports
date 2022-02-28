# Created by: Daniel Kahn Gillmor <dkg@fifthhorseman.net>

PORTNAME=	monkeysphere
PORTVERSION=	0.43
CATEGORIES=	security

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Use the OpenPGP web of trust to verify ssh connections

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error
RUN_DEPENDS=	gpg2:security/gnupg \
		lockfile:mail/procmail \
		bash:shells/bash \
		p5-Crypt-OpenSSL-RSA>=0:security/p5-Crypt-OpenSSL-RSA

USES=		gmake perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	dkg
GH_TAGNAME=	${PORTNAME}_${PORTVERSION}

SHEBANG_FILES=	src/monkeysphere* \
		src/share/c* src/share/defaultenv src/share/keytrans \
		src/transitions/0.23 src/transitions/0.28 \
		tests/basic tests/common tests/keytrans tests/phony*

USERS=	monkeysphere
GROUPS=	monkeysphere

MAKE_ARGS+=	ETCPREFIX=${PREFIX} MANPREFIX=${PREFIX}/man ETCSUFFIX=.sample

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -i '' 's|/etc/monkeysphere|${PREFIX}/etc/monkeysphere|g' \
	  ${WRKSRC}/etc/*.conf ${WRKSRC}/examples/* \
	  ${WRKSRC}/man/man1/* ${WRKSRC}/man/man7/* ${WRKSRC}/man/man8/* \
	  ${WRKSRC}/src/monkeysphere* \
	  ${WRKSRC}/src/share/c* ${WRKSRC}/src/share/defaultenv ${WRKSRC}/src/share/keytrans \
	  ${WRKSRC}/src/share/m/* ${WRKSRC}/src/share/mh/* \
	  ${WRKSRC}/tests/basic ${WRKSRC}/tests/keytrans ${WRKSRC}/tests/phony*
	@${REINPLACE_CMD} -i '' 's|/usr/share/monkeysphere|${PREFIX}/share/monkeysphere|g' \
	  ${WRKSRC}/etc/*.conf ${WRKSRC}/examples/* \
	  ${WRKSRC}/man/man1/* ${WRKSRC}/man/man7/* ${WRKSRC}/man/man8/* \
	  ${WRKSRC}/src/monkeysphere* \
	  ${WRKSRC}/src/share/c* ${WRKSRC}/src/share/defaultenv ${WRKSRC}/src/share/keytrans \
	  ${WRKSRC}/src/share/m/* ${WRKSRC}/src/share/mh/* \
	  ${WRKSRC}/tests/basic ${WRKSRC}/tests/keytrans ${WRKSRC}/tests/phony*
	@${REINPLACE_CMD} -i '' 's|/var/lib/monkeysphere|/var/monkeysphere|g' \
	  ${WRKSRC}/etc/*.conf ${WRKSRC}/examples/* \
	  ${WRKSRC}/man/man1/* ${WRKSRC}/man/man7/* ${WRKSRC}/man/man8/* \
	  ${WRKSRC}/src/monkeysphere* \
	  ${WRKSRC}/src/share/c* ${WRKSRC}/src/share/defaultenv ${WRKSRC}/src/share/keytrans \
	  ${WRKSRC}/src/share/m/* ${WRKSRC}/src/share/mh/* \
	  ${WRKSRC}/tests/basic ${WRKSRC}/tests/keytrans ${WRKSRC}/tests/phony*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/agent-transfer

.include <bsd.port.mk>
