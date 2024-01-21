PORTNAME=	cksfv
DISTVERSION=	1.3.15
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://zakalwe.fi/~shd/foss/cksfv/files/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Create or manipulate Simple File Verification (SFV) checksum files
WWW=		http://freecode.com/projects/cksfv

LICENSE=	GPLv2

USES=		tar:bz2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

PLIST_FILES=	bin/cksfv \
		share/man/man1/cksfv.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|^\(CC\)=|\1?=|' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
