PORTNAME=	distcache
DISTVERSION=	1.5.1
CATEGORIES=	security www
MASTER_SITES=	SF/distcache/1.%20distcache-devel/1.5.1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Distributed OpenSSL session caching tools

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool ssl tar:bzip2
USE_RC_SUBR=	dc_server
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-ssl=${OPENSSLBASE}
INSTALL_TARGET=	install-strip

SUB_LIST=	NAME=dc_server
PORTDOCS=	ANNOUNCE BUGS CHANGES FAQ README

OPTIONS_DEFINE=	DOCS

pre-configure:	# yes, post-patch won't work in this case
	@${GREP} -q 'define SSLeay_version' ${OPENSSLINC}/openssl/crypto.h \
	    && ${REINPLACE_CMD} -e 's,SSLeay_version,OpenSSL_version,' \
		${WRKSRC}/ssl/configure || :

post-install:
# Only executables are stripped with `install-strip', not the libraries
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

do-test:
	@cd ${TEST_WRKSRC} && ${SH} devel/test.sh

.include <bsd.port.mk>
