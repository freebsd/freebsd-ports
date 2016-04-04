# Created by: Daniel Kahn Gillmor <dkg@fifthhorseman.net>
# $FreeBSD$

PORTNAME=	monkeysphere
PORTVERSION=	0.36
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://archive.monkeysphere.info/debian/pool/monkeysphere/m/monkeysphere/
# hack for debian orig tarballs
DISTFILES=	${PORTNAME}_${DISTVERSION}.orig.tar.gz

MAINTAINER=	anarcat@koumbit.org
COMMENT=	Use the OpenPGP web of trust to verify ssh connections

RUN_DEPENDS=	gpg:security/gnupg1 \
		lockfile:mail/procmail \
		bash:shells/bash \
		p5-Crypt-OpenSSL-RSA>=0:security/p5-Crypt-OpenSSL-RSA \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1

USES=		shebangfix
SHEBANG_FILES=	src/share/checkperms src/transitions/0.23 \
		src/transitions/0.28 src/share/keytrans

USERS=	monkeysphere
GROUPS=	monkeysphere

MAKE_ARGS+=	ETCPREFIX=${PREFIX} MANPREFIX=${PREFIX}/man ETCSUFFIX=.sample

OPTIONS_DEFINE=	DOCS

# use proper system paths for FreeBSD instead of debian's:
post-patch:
	@${REINPLACE_CMD} -e 's|/etc/monkeysphere|${LOCALBASE}/etc/monkeysphere|g' \
	  ${WRKSRC}/src/share/defaultenv \
	  ${WRKSRC}/src/transitions/0.23 \
	  ${WRKSRC}/man/man1/monkeysphere.1 \
	  ${WRKSRC}/man/man8/monkeysphere-authentication.8 \
	  ${WRKSRC}/man/man8/monkeysphere-host.8 \
	  ${WRKSRC}/etc/monkeysphere-authentication.conf
	@${REINPLACE_CMD} -e 's|/var/lib/monkeysphere|/var/monkeysphere|g' \
	  ${WRKSRC}/src/transitions/0.23 \
	  ${WRKSRC}/man/man1/monkeysphere.1 \
	  ${WRKSRC}/man/man8/monkeysphere-authentication.8 \
	  ${WRKSRC}/man/man8/monkeysphere-host.8 \
	  ${WRKSRC}/src/monkeysphere-host \
	  ${WRKSRC}/src/monkeysphere-authentication
	@${REINPLACE_CMD} -e 's|/usr/share/monkeysphere|/usr/local/share/monkeysphere|g' \
	  ${WRKSRC}/src/monkeysphere-host \
	  ${WRKSRC}/src/monkeysphere-authentication \
	  ${WRKSRC}/src/monkeysphere
	# and clean up cruft from the sed replacements:
	${FIND} ${WRKSRC} -name '*.bak' -delete

.include <bsd.port.mk>
