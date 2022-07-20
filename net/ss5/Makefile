PORTNAME=	ss5
DISTVERSION=	3.8.9-8
PORTREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	raffaele.delorenzo@libero.it
COMMENT=	SOCKS v4/v5 application layer gateway with many features

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/License

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: ACMutex
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: ACMutex

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/-[0-9]+//}

USES=		ssl
USE_OPENLDAP=	yes
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-binpathbase=${PREFIX}/sbin \
		--with-docpathbase=${PREFIX}/share/doc \
		--with-confpathbase=${PREFIX}/etc \
		--with-libpath=${PREFIX}/lib

MAKE_ENV=	DATADIR=${DATADIR} EXAMPLESDIR=${EXAMPLESDIR}
MAKE_ARGS+=	CC="${CC}"

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local/etc/opt/ss5,${PREFIX}/etc/ss5,' \
		${WRKSRC}/include/config.h.in

post-install:
	${MKDIR} ${STAGEDIR}/var/log/ss5 ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/ss5.conf \
		${STAGEDIR}${PREFIX}/etc/ss5/ss5.conf.sample
	${INSTALL_DATA} ${WRKSRC}/conf/ss5.ha \
		${STAGEDIR}${PREFIX}/etc/ss5/ss5.ha.sample
	${INSTALL_DATA} ${WRKSRC}/conf/ss5.passwd \
		${STAGEDIR}${PREFIX}/etc/ss5/ss5.passwd.sample

.include <bsd.port.mk>
