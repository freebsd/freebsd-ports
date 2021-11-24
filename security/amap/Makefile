# Created by: Yonatan <onatan@gmail.com>

PORTNAME=	amap
PORTVERSION=	5.4
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/groups/thc

MAINTAINER=	onatan@gmail.com
COMMENT=	Application mapper

LICENSE=	AMAP GPLv2
LICENSE_COMB=	multi
LICENSE_NAME_AMAP=	amap license
LICENSE_FILE_AMAP=	${WRKSRC}/LICENCE.AMAP
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE.GNU
LICENSE_PERMS_AMAP=	dist-mirror dist-sell pkg-mirror pkg-sell

DEPRECATED=	Abandoned upstream, no new release for 10+ years. Please consider using security/nmap or security/rustscan
EXPIRATION_DATE=2022-03-31

USES=		ssl
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	SSL_PATH=${OPENSSLLIB} \
		CRYPTO_PATH=${OPENSSLLIB} \
		SSL_IPATH=${OPENSSLINC}

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS
PORTDOCS=	README TODO CHANGES AMAP-LIB-INTERFACE

LOCAL_CONF_FILES=	appdefs.resp appdefs.rpc appdefs.trig

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g; \
		 s|\(-DAMAP_PREFIX\)=\(\$$PREFIX\)|\1=\\\\\\"\2\\\\\\"|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O2|${CFLAGS}|; s|^CC=.*||' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|etc/|etc/amap/|g' ${WRKSRC}/amap-lib.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amap ${STAGEDIR}${PREFIX}/bin
	${LN} -s amap ${STAGEDIR}${PREFIX}/bin/amap6
	${INSTALL_PROGRAM} ${WRKSRC}/amapcrap ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/amap-lib.o ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.for i in amap.h amap-inc.h amap-lib.h
		${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.endfor
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for i in ${LOCAL_CONF_FILES}
		${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${ETCDIR}/${i}.sample
.endfor
	${INSTALL_MAN} ${WRKSRC}/amap.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
