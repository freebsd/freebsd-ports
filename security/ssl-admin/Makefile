# Created by: Eric Crist <ecrist@secure-computing.net>

PORTNAME=	ssl-admin
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	OpenSSL certificate manager with OpenVPN support

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

RUN_DEPENDS=	zip:archivers/zip

USES=		perl5 shebangfix tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	ecrist
USE_PERL5=	run

SHEBANG_FILES=	ssl-admin

GNU_CONFIGURE=	yes

MAKE_ENV=	ETCDIR=${PREFIX}/etc BINDIR=${PREFIX}/bin \
		MANDIR=${MANPREFIX}/man
NO_ARCH=	yes
SUB_FILES=	pkg-message

WRKSRC_SUBDIR=	perl

post-patch:
	${REINPLACE_CMD} -e 's|`which sed`|${SED}|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|{DESTDIR}/|{DESTDIR}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
