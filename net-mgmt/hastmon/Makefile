PORTNAME=	hastmon
PORTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Cluster monitoring daemon
WWW=		http://hastmon.googlecode.com/

LICENSE=	BSD2CLAUSE

DEPRECATED=	Depends on expiring devel/mk-configure
EXPIRATION_DATE=2025-09-30

BUILD_DEPENDS=	mk-configure>=0.20:devel/mk-configure

USE_GITHUB=	yes
GH_ACCOUNT=	trociny

USES=		ssl
MKCMAKE?=	${LOCALBASE}/bin/mkcmake
INSTALL_TARGET=	installdirs install
MAKE_ARGS=	MANDIR=${PREFIX}/share/man

PORTDOCS=	ChangeLog COPYRIGHT README

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} \
		-e "s|\(-lcrypto\)|-L${OPENSSLLIB} \1|g" \
		-e "s|\(-DHAVE_CRYPTO\)|-I${OPENSSLINC} \1|g" \
		${WRKSRC}/hastmon/Makefile \
		${WRKSRC}/hastmonctl/Makefile

do-build:
	${SETENV} ${MKCMAKE_ENV} ${MKCMAKE} -C ${WRKSRC}

do-install:
	${SETENV} ${MKCMAKE_ENV} DESTDIR=${STAGEDIR} \
		${MKCMAKE} -C ${WRKSRC} ${INSTALL_TARGET} ${MAKE_ARGS}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
