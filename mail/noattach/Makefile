# $FreeBSD$

PORTNAME=	noattach
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.rhnet.is/pub/noattach/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An attachment filter for Sendmail Milter

GNU_CONFIGURE=	yes
USE_RC_SUBR=	noattach
CFLAGS+=	${PTHREAD_CFLAGS:S=""==}
DOCSFILES=	AUTHORS THANKS INSTALL NEWS README TODO ChangeLog
SAMPLEFILES=	README noattach.patterns noattach.patterns.johncon

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITH_SENDMAIL_PORT)
CONFIGURE_ENV+=	MILTER_INCLUDES="${MILTERINC}"
MAKE_ENV+=	MILTER_INCLUDES="${MILTERINC}"
.endif

pre-configure:
	${REINPLACE_CMD} -e 's=-pthread=${PTHREAD_LIBS}=' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/noattach ${STAGEDIR}${PREFIX}/libexec/noattach
	${INSTALL_MAN} ${WRKSRC}/noattach.8 ${STAGEDIR}${PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/examples/noattach.patterns \
		${STAGEDIR}${PREFIX}/etc/noattach.patterns-dist
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${SAMPLEFILES}
	${INSTALL_DATA} ${WRKSRC}/examples/${i} ${STAGEDIR}${EXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
