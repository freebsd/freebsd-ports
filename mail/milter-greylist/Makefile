# New ports collection makefile for:	milter-greylist
# Date created:				27 Apr 2004
# Whom:					Cyril Guibourg
#
# $FreeBSD$
#

PORTNAME=	milter-greylist
PORTVERSION=	2.0
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/
DISTNAME=	milter-greylist-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	aragorn+ports@teaser.fr
COMMENT=	Easy-to-use greylist milter for sendmail

MAN5=		greylist.conf.5
MAN8=		milter-greylist.8

CFLAGS+=	${PTHREAD_CFLAGS}
LIBS+=		${PTHREAD_LIBS}

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-user=smmsp
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LIBS="${LIBS}"

ALL_TARGET=	milter-greylist

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

CONFLICTS=	milter-greylist-devel-[1-9]*.*

post-extract:
	@${SED}	${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/milter-greylist.sh > ${WRKSRC}/milter-greylist.sh

do-install:
	@${MKDIR} ${PREFIX}/etc/mail
	@${INSTALL_PROGRAM} ${WRKSRC}/milter-greylist ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/greylist.conf.5 ${PREFIX}/man/man5
	@${INSTALL_MAN} ${WRKSRC}/milter-greylist.8 ${PREFIX}/man/man8
	@${INSTALL_DATA} ${WRKSRC}/greylist.conf \
			${PREFIX}/etc/mail/greylist.conf.sample
	@${INSTALL_SCRIPT} ${WRKSRC}/milter-greylist.sh ${PREFIX}/etc/rc.d/

post-install:
	@${MKDIR} /var/milter-greylist
	@${CHOWN} smmsp /var/milter-greylist
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/greylist.conf ${EXAMPLESDIR}
.endif

	@${TEST} -f /var/db/milter-greylist/greylist.db && ( \
		${ECHO} "************************************************************"; \
		${ECHO} "************************************************************"; \
		${ECHO} "**                                                        **"; \
		${ECHO} "**                        WARNING                         **"; \
		${ECHO} "**                                                        **"; \
		${ECHO} "** The default dump file location has changed.            **"; \
		${ECHO} "** Please move greylist.db from /var/db/milter-greylist/  **"; \
		${ECHO} "** to /var/milter-greylist/ and update your greylist.conf **"; \
		${ECHO} "** accordingly.                                           **"; \
		${ECHO} "**                                                        **"; \
		${ECHO} "************************************************************"; \
		${ECHO} "************************************************************"; \
	) || ${TRUE}

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
