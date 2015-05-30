# Created by: Peter Hollaubek <fifteen@inext.hu>
# $FreeBSD$

PORTNAME=	sentinel
PORTVERSION=	1.7b
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF/smfilter/${PORTNAME}/Sentinel%20${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Sendmail milter API implementation

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITHOUT_SENTINEL_DECODE_SUBJECT)
CFLAGS+=	-DDO_NOT_DECODE_SUBJECT
.endif

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${CC} ${CFLAGS} -o ${PORTNAME} sentinel.c ${LDFLAGS} \
		-lmilter -lpcre -lpcreposix -lpthread)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sentinel ${STAGEDIR}${PREFIX}/sbin/
	@${MKDIR} ${STAGEDIR}/var/spool/sentinel
	${INSTALL_DATA} ${FILESDIR}/000.sentinel.sh ${STAGEDIR}${PREFIX}/etc/rc.d/sentinel.sh-dist
	${INSTALL_DATA} ${WRKSRC}/sentinel.cf.SAMPLE ${STAGEDIR}${PREFIX}/etc/sentinel.cf.dist
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.FreeBSD ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
