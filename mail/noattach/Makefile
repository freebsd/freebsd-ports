# New ports collection makefile for:	noattach
# Date created:				10. Feb 2002
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	noattach
PORTVERSION=	1.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.rhnet.is/pub/noattach/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An attachment filter for Sendmail Milter

CFLAGS+=	${PTHREAD_CFLAGS:S=""==}
GNU_CONFIGURE=	yes
MAN8=		noattach.8
DOCSFILES=	AUTHORS THANKS INSTALL NEWS README TODO ChangeLog
SAMPLEFILES=	README noattach.patterns noattach.patterns.johncon
.if defined(SENDMAIL_WITH_LDAP)
CONFIGURE_ARGS+=	--enable-ldap
.endif

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITH_SENDMAIL_PORT)
CONFIGURE_ENV+=	MILTER_INCLUDES="${MILTERINC}"
MAKE_ENV+=	MILTER_INCLUDES="${MILTERINC}"
.endif

pre-configure:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=" ${FILESDIR}/noattach.sh \
		> ${WRKSRC}/noattach.sh
	${REINPLACE_CMD} -e 's=-pthread=${PTHREAD_LIBS}=' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/noattach ${PREFIX}/libexec/noattach
	${INSTALL_SCRIPT} ${WRKSRC}/noattach.sh \
		${PREFIX}/etc/rc.d/noattach.sh.sample
	${INSTALL_DATA} ${WRKSRC}/examples/noattach.patterns \
		 ${PREFIX}/etc/noattach.patterns-dist
	${INSTALL_MAN} ${WRKSRC}/noattach.8 ${PREFIX}/man/man8/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
.for i in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.for i in ${SAMPLEFILES}
	${INSTALL_DATA} ${WRKSRC}/examples/${i} ${EXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
