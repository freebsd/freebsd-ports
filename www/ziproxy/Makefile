# New ports collection makefile for:	ziproxy
# Date created:				2006-07-28
# Whom:					Pankov Pavel <pankov_p@mail.ru>
#
# $FreeBSD$

PORTNAME=		ziproxy
PORTVERSION=		3.1.3
CATEGORIES=		www
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=		pankov_p@mail.ru
COMMENT=		A forwarding, non-caching, compressing proxy server

LIB_DEPENDS=		ungif.5:${PORTSDIR}/graphics/libungif \
			png.6:${PORTSDIR}/graphics/png \
			jpeg.11:${PORTSDIR}/graphics/jpeg

USE_BZIP2=		yes

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/COPYING

CFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

CONFIGURE_ENV+=		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cfgfile="${PREFIX}/etc/ziproxy/ziproxy.conf"

PORTDOCS=		README README.tools JPEG2000.txt

MAN1=			ziproxy.1 ziproxylogtool.1
MANCOMPRESSED=		no

USE_RC_SUBR=		ziproxy

SUB_FILES+=		pkg-message

OPTIONS+=		JPEG2000 "Build with JPEG2000 support" on

ERROR_FILES=		400.html 403.html 404.html 407.html 408.html 409.html \
			500.html 503.html
SAMPLE_CONFIG_FILES=	bo_exception.list change_tos.list deny.list http.passwd \
			noprocess.list replace.list replace_ct.list \
			ziproxy.conf

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
	                  -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/etc/ziproxy/ziproxy.conf

post-install:
	@${MKDIR} ${PREFIX}/etc/ziproxy
.for FILE in ${SAMPLE_CONFIG_FILES}
	@${INSTALL_DATA} ${WRKSRC}/etc/ziproxy/${FILE} ${PREFIX}/etc/ziproxy/${FILE}.sample
.endfor
	@if [ ! -f ${PREFIX}/etc/ziproxy/ziproxy.conf ]; then \
		${CP} -p ${WRKSRC}/etc/ziproxy/ziproxy.conf ${PREFIX}/etc/ziproxy/ziproxy.conf ; \
	fi

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${DOC}
.endfor
.endif

	@${MKDIR} ${DATADIR}/error
.for FILE in ${ERROR_FILES}
	@${INSTALL_DATA} ${WRKSRC}/var/ziproxy/error/${FILE} ${DATADIR}/error/${FILE}
.endfor

	@${INSTALL_SCRIPT} ${WRKSRC}/src/tools/ziproxy_genhtml_stats.sh ${PREFIX}/bin

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_JPEG2000)
CONFIGURE_ARGS+=	--with-jasper
LIB_DEPENDS+=		jasper.4:${PORTSDIR}/graphics/jasper
.endif

.include <bsd.port.post.mk>
