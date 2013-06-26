# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	proxychains-ng
PORTVERSION=	4.5
CATEGORIES=	net security
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	${PORTNAME:S/-ng//}-${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Redirect connection through proxy servers

LICENSE=	GPLv2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes
ALL_TARGET=	all
INSTALL_TARGET=	install install-config
USE_LDCONFIG=	yes

CONFLICTS=	proxychains-[0-9]*

PORTDOCS=	AUTHORS ChangeLog README TODO

.include <bsd.port.options.mk>

post-configure:
	@${ECHO_CMD} "PXCHAINS=proxychains" >> ${WRKSRC}/config.mak
	@${ECHO_CMD} "LDSO_PATHNAME=libproxychains-4.so" >> ${WRKSRC}/config.mak

post-patch:
	@${REINPLACE_CMD} \
		-e 's|$$(DESTDIR)/$$(sysconfdir)/|$$(DESTDIR)/$$(sysconfdir)/proxychains.conf.sample|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e 's|libproxychains4.so|libproxychains-4.so|' \
		${WRKSRC}/src/proxyresolv

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/proxyresolv ${PREFIX}/bin
	@[ -f ${PREFIX}/etc/proxychains.conf ] || ${CP} ${PREFIX}/etc/proxychains.conf.sample \
		${PREFIX}/etc/proxychains.conf

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
