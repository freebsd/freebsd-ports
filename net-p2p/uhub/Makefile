# Created by: Yashin Dmitry <yashin.dm@gmail.com>
# $FreeBSD$

PORTNAME=	uhub
PORTVERSION=	0.5.0
DISTVERSIONSUFFIX=	-src
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.extatic.org/downloads/uhub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance peer-to-peer hub for the ADC network

LICENSE=	GPLv3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USERS=		uhub
GROUPS=		uhub

USES=		cmake perl5
USE_RC_SUBR=	uhub
USE_PERL5=	build

CFLAGS+=	-fPIC -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		OPENSSL SQLITE
OPTIONS_DEFAULT=	OPENSSL SQLITE
OPTIONS_SUB=		yes

OPENSSL_USE=		openssl=yes
OPENSSL_CMAKE_OFF=	-DSSL_SUPPORT:BOOL=OFF
SQLITE_USES=		sqlite
SQLITE_CMAKE_OFF=	-DSQLITE_SUPPORT:BOOL=OFF

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/DESTINATION/s|^|#|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's| /usr/lib/| ${PREFIX}/lib/|g ; \
		 s|=/etc/uhub/|=${ETCDIR}/|g' ${WRKSRC}/doc/uhub.conf
	@${REINPLACE_CMD} -e \
		's|"/etc/uhub/|"${ETCDIR}/|' ${WRKSRC}/src/uhub.h

do-install:
	(cd ${INSTALL_WRKSRC} && ${INSTALL_PROGRAM} uhub \
		${STAGEDIR}${PREFIX}/bin)
.if ${PORT_OPTIONS:MSQLITE}
	(cd ${INSTALL_WRKSRC} && ${INSTALL_PROGRAM} uhub-passwd \
		${STAGEDIR}${PREFIX}/bin)
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/uhub
	(cd ${INSTALL_WRKSRC} && ${INSTALL_LIB} mod_*.so \
		${STAGEDIR}${PREFIX}/lib/uhub)
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for i in uhub.conf users.conf
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${ETCDIR}/${i}.sample)
.endfor
.for i in motd.txt rules.txt
	@${ECHO_CMD} -n > ${STAGEDIR}${ETCDIR}/${i}.sample
.endfor

.include <bsd.port.mk>
