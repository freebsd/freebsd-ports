# $FreeBSD$

PORTNAME=	noattach
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.rhnet.is/pub/noattach/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Attachment filter for Sendmail Milter

GNU_CONFIGURE=	yes
USE_RC_SUBR=	noattach
DOCSFILES=	AUTHORS THANKS INSTALL NEWS README TODO ChangeLog
SAMPLEFILES=	README noattach.patterns noattach.patterns.johncon

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITH_SENDMAIL_PORT)
CONFIGURE_ENV+=	MILTER_INCLUDES="${MILTERINC}"
MAKE_ENV+=	MILTER_INCLUDES="${MILTERINC}"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/noattach ${STAGEDIR}${PREFIX}/libexec/noattach
	${INSTALL_MAN} ${WRKSRC}/noattach.8 ${STAGEDIR}${PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/examples/noattach.patterns \
		${STAGEDIR}${PREFIX}/etc/noattach.patterns-dist

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${SAMPLEFILES}
	${INSTALL_DATA} ${WRKSRC}/examples/${i} ${STAGEDIR}${EXAMPLESDIR}/
.endfor

.include <bsd.port.post.mk>
