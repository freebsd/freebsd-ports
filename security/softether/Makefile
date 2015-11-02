# $FreeBSD$

PORTNAME=	softether
PORTVERSION=	4.18.9570
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.softether-download.com/files/softether/v4.18-9570-rtm-2015.07.26-tree/Source_Code/
DISTNAME=	${PORTNAME}-src-v4.18-9570-rtm

MAINTAINER=	net@arrishq.net
COMMENT=	Softether VPN solution

LICENSE=	GPLv2

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS.TXT ChangeLog LICENSE README THIRD_PARTY.TXT WARNING.TXT
DOS2UNIX_FILES=	AUTHORS.TXT ChangeLog LICENSE README THIRD_PARTY.TXT \
		WARNING.TXT \
		src/Cedar/Cedar.h \
		src/Cedar/Cedar.h \
		src/Cedar/Client.h \
		src/Cedar/Nat.h \
		src/Cedar/Server.c \
		src/Mayaqua/Cfg.c \
		src/Mayaqua/Cfg.h \
		src/Mayaqua/Network.c \
		src/Mayaqua/Kernel.c \
		src/Mayaqua/Table.h \
		src/Mayaqua/Unix.c

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	i386 amd64

USE_OPENSSL=	yes
USES=		dos2unix gmake iconv:wchar_t ncurses readline
USE_RC_SUBR=	softether_bridge softether_client softether_server
SUB_FILES=	vpncmd
MAKE_JOBS_UNSAFE=	yes

# a pity the source directory has such a naming scheme, but well
WRKSRC=		${WRKDIR}/v4.18-9570

ALL_TARGET=	build

.include <bsd.port.options.mk>

# requires OpenSSL from ports
.if ${OSVERSION} < 1000000
WITH_OPENSSL_PORT=	yes
.endif

# skip configure at all and copy the corresponding Makefile in place
post-extract:
.if ${ARCH} != "amd64"
	@${CP} ${WRKSRC}/src/makefiles/freebsd_32bit.mak ${WRKSRC}/Makefile
.else
	@${CP} ${WRKSRC}/src/makefiles/freebsd_64bit.mak ${WRKSRC}/Makefile
.endif

# pull in user specific CFLAGS and LDFLAGS
	@${REINPLACE_CMD} -e "s|OPTIONS_COMPILE_RELEASE=|OPTIONS_COMPILE_RELEASE=${CFLAGS} |g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|OPTIONS_LINK_RELEASE=|OPTIONS_LINK_RELEASE=${LDFLAGS} |g" ${WRKSRC}/Makefile

# manually install to ${PREFIX}/libexec/softether, then the final install will copy scripts
# into ${PREFIX}/sbin
do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/softether
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vpnbridge/vpnbridge ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/vpnbridge
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vpnclient/vpnclient ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/vpnclient
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vpncmd/vpncmd ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/vpncmd
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vpnserver/vpnserver ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/vpnserver
	${INSTALL_DATA} ${WRKSRC}/bin/vpnserver/hamcore.se2 ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/hamcore.se2
	${INSTALL_SCRIPT} ${WRKDIR}/vpncmd ${STAGEDIR}/${PREFIX}/sbin/vpncmd

post-install:
.for i in vpnbridge vpnclient vpncmd vpnserver
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/${i}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
