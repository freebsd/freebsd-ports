# Created by: Thomas Lotterer <thomas.lotterer@cw.com>
# $FreeBSD$

PORTNAME=	lmtp2nntp
PORTVERSION=	1.4.1
CATEGORIES=	mail news
MASTER_SITES=	OSSP/tool/${PORTNAME}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	OSSP mail to news gateway

LIB_DEPENDS=	libstr.so:${PORTSDIR}/devel/str \
		libex.so:${PORTSDIR}/devel/ossp-ex \
		libsa.so:${PORTSDIR}/net/ossp-sa \
		libvar.so:${PORTSDIR}/devel/ossp-var

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ex=${LOCALBASE} --with-str=${LOCALBASE} \
		--with-sa=${LOCALBASE} --with-var=${LOCALBASE}

PLIST_FILES=	sbin/lmtp2nntp \
		man/man8/lmtp2nntp.8.gz
PORTDOCS=	INSTALL README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

# Try to fix parallel builds (-jX)
post-patch:
	@${REINPLACE_CMD} -e '/^all:/s, _SUBDIRS_all,, ; \
		/^$$(PROG)/s,$$, _SUBDIRS_all,' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

check: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} check)

regression-test: check

.include <bsd.port.mk>
