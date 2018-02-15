# Created by: Yashin Dmitry <yashin.dm@gmail.com>
# $FreeBSD$

PORTNAME=	uhub
PORTVERSION=	0.5.0
DISTVERSIONSUFFIX=	-src
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.extatic.org/downloads/uhub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance peer-to-peer hub for the ADC network

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	fails to compile: CPUINFO not defined

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		cmake perl5 sqlite
USE_RC_SUBR=	uhub
USE_PERL5=	build

USERS=		uhub
GROUPS=		uhub

CFLAGS+=	-fPIC

OPTIONS_DEFINE=		OPENSSL
OPTIONS_DEFAULT=	OPENSSL SQLITE
OPTIONS_SUB=		yes

OPENSSL_USES=		ssl
OPENSSL_CMAKE_BOOL=	SSL_SUPPORT

post-patch:
	@${REINPLACE_CMD} -e \
		'/DESTINATION/s|^|#|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's| /usr/lib/| ${PREFIX}/lib/|g ; \
		 s|=/etc/uhub/|=${ETCDIR}/|g' ${WRKSRC}/doc/uhub.conf
	@${REINPLACE_CMD} -e \
		's|"/etc/uhub/|"${ETCDIR}/|' ${WRKSRC}/src/uhub.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uhub ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/uhub-passwd ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/uhub
	${INSTALL_LIB} ${WRKSRC}/mod_*.so ${STAGEDIR}${PREFIX}/lib/uhub
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for i in uhub.conf users.conf
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${ETCDIR}/${i}.sample
.endfor
.for i in motd.txt rules.txt
	@${ECHO_CMD} -n > ${STAGEDIR}${ETCDIR}/${i}.sample
.endfor

.include <bsd.port.mk>
