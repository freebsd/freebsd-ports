# $FreeBSD$

PORTNAME=	hblock
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.1
CATEGORIES=	net

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Adblocker using automatically generated hosts file

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USE_GITHUB=	yes
GH_ACCOUNT=	hectorm

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	PACKAGES.md README.md SOURCES.md

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} \
		-e 's,$${ETCDIR?}\/hosts,/etc/hosts,g' \
		-e '/hosts/!s,/etc,${PREFIX}/etc,g' \
		${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
