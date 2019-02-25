# Created by: Daniel Kahn Gillmor <dkg@fifthhorseman.net>
# $FreeBSD$

PORTNAME=	monkeysphere
PORTVERSION=	0.42
CATEGORIES=	security
MASTER_SITES=	http://archive.monkeysphere.info/debian/pool/monkeysphere/m/monkeysphere/
DISTFILES=	${PORTNAME}_${DISTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Use the OpenPGP web of trust to verify ssh connections

LICENSE=	GPLv3

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error
RUN_DEPENDS=	gpg2:security/gnupg \
		lockfile:mail/procmail \
		bash:shells/bash \
		p5-Crypt-OpenSSL-RSA>=0:security/p5-Crypt-OpenSSL-RSA \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1

USES=		gmake shebangfix

SHEBANG_FILES=	src/share/checkperms src/transitions/0.23 \
		src/transitions/0.28 src/share/keytrans

USERS=	monkeysphere
GROUPS=	monkeysphere

MAKE_ARGS+=	ETCPREFIX=${PREFIX} MANPREFIX=${PREFIX}/man ETCSUFFIX=.sample

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -i '' 's|/etc/monkeysphere|${PREFIX}/etc/monkeysphere|g' \
	  ${WRKSRC}/src/share/defaultenv \
	  ${WRKSRC}/src/transitions/0.23 \
	  ${WRKSRC}/man/man1/monkeysphere.1 \
	  ${WRKSRC}/man/man8/monkeysphere-authentication.8 \
	  ${WRKSRC}/man/man8/monkeysphere-host.8 \
	  ${WRKSRC}/etc/monkeysphere-authentication.conf
	@${REINPLACE_CMD} -i '' 's|/var/lib/monkeysphere|/var/monkeysphere|g' \
	  ${WRKSRC}/src/transitions/0.23 \
	  ${WRKSRC}/man/man1/monkeysphere.1 \
	  ${WRKSRC}/man/man8/monkeysphere-authentication.8 \
	  ${WRKSRC}/man/man8/monkeysphere-host.8 \
	  ${WRKSRC}/src/monkeysphere-host \
	  ${WRKSRC}/src/monkeysphere-authentication
	@${REINPLACE_CMD} -i '' 's|/usr/share/monkeysphere|${PREFIX}/share/monkeysphere|g' \
	  ${WRKSRC}/src/monkeysphere-host \
	  ${WRKSRC}/src/monkeysphere-authentication \
	  ${WRKSRC}/src/monkeysphere
	# and clean up cruft from any patches or sed replacements:
	${FIND} ${WRKSRC} \( -name \*.bak -o -name \*.orig \) -delete
	@${REINPLACE_CMD} 's|gcc|${CC}|g' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/agent-transfer

.include <bsd.port.mk>
