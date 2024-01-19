PORTNAME=	keama
ISCVERSION=	4.4.3-P1
PORTVERSION=	${ISCVERSION:S/-P/P/:S/b/.b/:S/a/.a/:S/rc/.rc/}
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ISC/${PORTNAME}/${PORTVERSION:S/P/-P/g} \
		ZI
DISTNAME=	dhcp-${ISCVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Kea migration assistant
WWW=		https://gitlab.isc.org/isc-projects/dhcp/-/wikis/kea-migration-assistant

LICENSE=	MPL20

USES=		cpe gmake

CPE_VENDOR=	isc

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=--localstatedir=/var
CPPFLAGS+=	-D_PATH_DHCPD_CONF='\"${PREFIX}/etc/dhcpd.conf\"'
CFLAGS+=	-fPIC
BUILD_WRKSRC=	${WRKSRC}/keama
MAN_COMPRESSED=	no
SCRIPTS_ENV+=	PKG_PREFIX=${PREFIX}

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

PLIST_FILES=	sbin/keama share/man/man8/keama.8.gz \
		%%PORTDOCS%%%%DOCSDIR%%/ChangeLog.md \
		%%PORTDOCS%%%%DOCSDIR%%/README.md \

do-install:
	${SETENV} DESTDIR=${STAGEDIR} ${MAKE} -C ${WRKSRC}/keama install

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/keama/*.md ${STAGEDIR}/${DOCSDIR}/

.include <bsd.port.mk>
