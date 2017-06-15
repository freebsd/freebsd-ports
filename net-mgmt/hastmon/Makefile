# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	hastmon
PORTVERSION=	0.3.2
CATEGORIES=	net-mgmt

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Cluster monitoring daemon

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	mk-configure>=0.20:devel/mk-configure

USE_GITHUB=	yes
GH_ACCOUNT=	trociny

USES=		ssl
MKCMAKE?=	${LOCALBASE}/bin/mkcmake
INSTALL_TARGET=	installdirs install

PORTDOCS=	ChangeLog COPYRIGHT README

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
		${MKCMAKE} -C ${WRKSRC} ${INSTALL_TARGET}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
