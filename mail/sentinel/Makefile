# Created by: Peter Hollaubek <fifteen@inext.hu>
# $FreeBSD$

PORTNAME=	sentinel
PORTVERSION=	1.7b
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	SF/smfilter/${PORTNAME}/Sentinel%20${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Sendmail milter API implementation

LIB_DEPENDS=	libpcre.so:devel/pcre

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NOSUBJECT DOCS

NOSUBJECT_DESC=		do not decode subject
NOSUBJECT_CFLAGS=	-DDO_NOT_DECODE_SUBJECT

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${CC} ${CFLAGS} -o ${PORTNAME} sentinel.c ${LDFLAGS} \
		-lmilter -lpcre -lpcreposix -lpthread)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sentinel ${STAGEDIR}${PREFIX}/sbin/
	@${MKDIR} ${STAGEDIR}/var/spool/sentinel
	${INSTALL_DATA} ${FILESDIR}/000.sentinel.sh ${STAGEDIR}${PREFIX}/etc/rc.d/sentinel.sh-dist
	${INSTALL_DATA} ${WRKSRC}/sentinel.cf.SAMPLE ${STAGEDIR}${PREFIX}/etc/sentinel.cf.dist

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.FreeBSD ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
