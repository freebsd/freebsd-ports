# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	rsyncrypto
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	SF

MAINTAINER=	linpct@gmail.com
COMMENT=	Rsync Friendly File Encryption

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libargtable2.so:devel/argtable
RUN_DEPENDS=	rsync:net/rsync \
		gzip:archivers/gzip

LDFLAGS+=	-L${LOCALBASE}/lib/
CPPFLAGS+=	-I${LOCALBASE}/include/

GNU_CONFIGURE=	yes
USES=		gmake

PLIST_FILES=	bin/rsyncrypto \
		bin/rsyncrypto_recover \
		man/man1/rsyncrypto.1.gz \
		man/man1/rsyncrypto_recover.1.gz

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} ${PORTNAME} requires archivers/gzip be built
	@${ECHO_MSG} with the RSYNCABLE flag to run properly
	@${ECHO_MSG}

.include <bsd.port.mk>
