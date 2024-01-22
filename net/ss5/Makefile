PORTNAME=	ss5
DISTVERSION=	3.8.9-8
PORTREVISION=	4
CATEGORIES=	net security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	raffaele.delorenzo@libero.it
COMMENT=	SOCKS v4/v5 application layer gateway with many features
WWW=		https://ss5.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/License

USES=		ldap ssl
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-binpathbase=${PREFIX}/sbin \
		--with-docpathbase=${PREFIX}/share/doc \
		--with-confpathbase=${PREFIX}/etc \
		--with-libpath=${PREFIX}/lib

MAKE_ARGS+=	CC="${CC}"
MAKE_ENV=	DATADIR=${DATADIR} EXAMPLESDIR=${EXAMPLESDIR}

CFLAGS+=	-fcommon

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/-[0-9]+//}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

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
