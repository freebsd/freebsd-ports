# New ports collection makefile for:	noattach
# Date created:				10. Feb 2002
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	noattach
PORTVERSION=	1.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.rhnet.is/pub/noattach/

MAINTAINER=	dinoex@FreeBSD.org

.if !defined(SENDMAIL_MILTER_IN_BASE)
BUILD_DEPENDS=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/sendmail
.endif

CFLAGS+=	${PTHREAD_CFLAGS:S=""==}
GNU_CONFIGURE=	yes
MAN8=		noattach.8
DOCSFILES=	AUTHORS THANKS COPYING INSTALL NEWS README TODO ChangeLog
SAMPLEFILES=	README noattach.patterns noattach.patterns.johncon
.if defined(SENDMAIL_WITH_LDAP)
CONFIGURE_ARGS+=	--enable-ldap
.endif

.include <bsd.port.pre.mk>

.if defined(SENDMAIL_WITHOUT_MILTER)
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} You must unset variable SENDMAIL_WITHOUT_MILTER,
	@${ECHO_MSG} and rebuild sendmail in the ports
	@${FALSE}
.endif

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=" ${FILESDIR}/noattach.sh \
		> ${WRKSRC}/noattach.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/noattach ${PREFIX}/libexec/noattach
	${INSTALL_SCRIPT} ${WRKSRC}/noattach.sh \
		${PREFIX}/etc/rc.d/noattach.sh.sample
	${INSTALL_DATA} ${WRKSRC}/examples/noattach.patterns \
		 ${PREFIX}/etc/noattach.patterns-dist
	${INSTALL_MAN} ${WRKSRC}/doc/noattach.8 ${PREFIX}/man/man8/
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
