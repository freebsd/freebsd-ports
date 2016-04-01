# Created by: Eric Crist <ecrist@secure-computing.net>
# $FreeBSD$

PORTNAME=	ssl-admin
DISTVERSION=	1.2.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.secure-computing.net/pub/FreeBSD/ports/ssl-admin/ \
		ftp://ftp2.secure-computing.net/pub/FreeBSD/ports/ssl-admin/

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	OpenSSL certificate manager with OpenVPN support

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	zip:archivers/zip

USES=		perl5 shebangfix tar:xz
SHEBANG_FILES=	ssl-admin
USE_PERL5=	run
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message
MAKE_ENV=	ETCDIR=${PREFIX}/etc BINDIR=${PREFIX}/bin \
		MANDIR=${MANPREFIX}/man
NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e 's|`which sed`|${SED}|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|{DESTDIR}/|{DESTDIR}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
