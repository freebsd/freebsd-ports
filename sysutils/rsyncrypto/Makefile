PORTNAME=	rsyncrypto
PORTVERSION=	1.14
PORTREVISION=	2
CATEGORIES=	sysutils net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rsync Friendly File Encryption
WWW=		https://rsyncrypto.lingnu.com/

LICENSE=	GPLv2+

LIB_DEPENDS=	libargtable2.so:devel/argtable
RUN_DEPENDS=	rsync:net/rsync

USES=		compiler:c++11-lang gmake localbase ssl tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/rsyncrypto \
		bin/rsyncrypto_recover \
		share/man/man1/rsyncrypto.1.gz \
		share/man/man1/rsyncrypto_recover.1.gz
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

post-patch:
# Inhibit the check for RSA_get0_factors() to support older OpenSSL versions
	@${REINPLACE_CMD} -e '/RSA_get0_factors/,+49d' ${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
