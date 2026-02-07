PORTNAME=	ssl-admin
DISTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://github.com/ecrist/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	OpenSSL certificate manager with OpenVPN support
WWW=		https://github.com/ecrist/ssl-admin/

LICENSE=	BSD3CLAUSE

USES=		perl5 shebangfix tar:xz
USE_PERL5=	run

SHEBANG_FILES=	ssl-admin

HAS_CONFIGURE=	yes

MAKE_ENV=	BINDIR=${PREFIX}/bin \
		ETCDIR=${PREFIX}/etc \
		MANDIR=${PREFIX}/share/man
NO_ARCH=	yes
SUB_FILES=	pkg-message

post-patch:
	${REINPLACE_CMD} -e 's|`which sed`|${SED}|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|{DESTDIR}/|{DESTDIR}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
