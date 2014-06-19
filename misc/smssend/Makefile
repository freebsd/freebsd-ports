# Created by: Miklos Niedermayer <mico@bsd.hu>
# $FreeBSD$

PORTNAME=	smssend
PORTVERSION=	3.5
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	laszlof

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to send a SMS to any GSM

LIB_DEPENDS=	libskyutils-2.9.so:${PORTSDIR}/misc/skyutils

USES=		shebangfix
SHEBANG_FILES=	bestsms.sh email2smssend
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/smssend

.include <bsd.port.mk>
