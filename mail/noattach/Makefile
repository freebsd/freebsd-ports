# New ports collection makefile for:	noattach
# Date created:				10. Feb 2002
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	noattach
PORTVERSION=	1.0beta10
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.rhnet.is/pub/noattach/

MAINTAINER=	dinoex@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/sendmail

CFLAGS+=	${PTHREAD_CFLAGS:S=""==}
FLAGS+=		${PTHREAD_LIBS}
GNU_CONFIGURE=	yes
DOCSFILES=	AUTHORS THANKS COPYING INSTALL NEWS README ChangeLog
SAMPLEFILES=	README noattach.patterns noattach.patterns.johncon

.include <bsd.port.pre.mk>

.if defined(SENDMAIL_WITHOUT_MILTER)
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} You must unset variable SENDMAIL_WITHOUT_MILTER,
	@${ECHO_MSG} and rebuild sendmail in the ports
	@${FALSE}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/noattach ${PREFIX}/libexec/noattach
	${INSTALL_SCRIPT} ${FILESDIR}/noattach.sh \
		${PREFIX}/etc/rc.d/noattach.sh.sample
	${INSTALL_DATA} ${WRKSRC}/examples/noattach.patterns \
		 ${PREFIX}/etc/noattach.patterns-dist
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
