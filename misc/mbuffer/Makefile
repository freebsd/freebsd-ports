# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mbuffer
PORTVERSION=	20200505
CATEGORIES=	misc
MASTER_SITES=	http://www.maier-komor.de/software/mbuffer/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Tool for buffering data streams

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	gtar:archivers/gtar

USES=		localbase ssl tar:tgz

GNU_CONFIGURE=	yes

# for --ignore-failed-read
TEST_ARGS=	TAR=gtar
TEST_TARGET=	check

OPTIONS_DEFINE=		GCRYPT MHASH RHASH
OPTIONS_DEFAULT=	MHASH

GCRYPT_DESC=	Use gcrypt for hash generation
MHASH_DESC=	Use mhash for hash generation
RHASH_DESC=	Use rhash for hash generation

GCRYPT_RUN_DEPENDS=	libgcrypt>=1.8.4_1:security/libgcrypt
MHASH_RUN_DEPENDS=	mhash>=0.9.9.9_5:security/mhash
RHASH_RUN_DEPENDS=	rhash>=1.3.5:security/rhash

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mbuffer
	${MV} ${STAGEDIR}${PREFIX}/etc/mbuffer.rc \
		${STAGEDIR}${PREFIX}/etc/mbuffer.rc.sample

.include <bsd.port.mk>
