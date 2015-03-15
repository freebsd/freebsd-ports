# $FreeBSD$

PORTNAME=	tlsdate
PORTVERSION=	0.0.11
CATEGORIES=	sysutils
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-${GH_COMMIT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure parasitic rdate replacement

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ioerror
GH_COMMIT=	5be06de
GH_TAGNAME=	${GH_COMMIT}

GNU_CONFIGURE=	yes
USES=		autoreconf libtool pkgconfig
USE_OPENSSL=	yes

PLIST_SUB+=	PKGNAME=${PKGNAME}

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS+=	libevent.so:${PORTSDIR}/devel/libevent2

post-patch:
	${REINPLACE_CMD} -e '/doc_DATA\+= LICENSE/d' ${WRKSRC}/Makefile.am

post-install:
	@${CHMOD} o+rx ${STAGEDIR}/${PREFIX}/etc/tlsdate ${STAGEDIR}/${PREFIX}/etc/tlsdate/ca-roots
	@${MKDIR} ${STAGEDIR}/${PREFIX}/share/licenses/${PKGNAME}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${PREFIX}/share/licenses/${PKGNAME}

regression-test: build
	@cd ${WRKSRC} && make test

.include <bsd.port.mk>
