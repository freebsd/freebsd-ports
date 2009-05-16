# New ports collection makefile for:	milter-greylist-devel
# Date created:				11 Dec 2004
# Whom:					Cyril Guibourg
#
# $FreeBSD$
#

PORTNAME=	milter-greylist-devel
DISTVERSION=	4.3.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/
DISTNAME=	milter-greylist-${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Easy-to-use greylist milter for sendmail (development)

MAKE_JOBS_SAFE=  yes

MAN5=		greylist.conf.5
MAN8=		milter-greylist.8

CFLAGS+=	${PTHREAD_CFLAGS}
LIBS+=		${PTHREAD_LIBS}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-user=smmsp
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LIBS="${LIBS}"

ALL_TARGET=	milter-greylist

USE_RC_SUBR=	milter-greylist
SUB_FILES+=	pkg-message

CONFLICTS=	milter-greylist-[1-9]*.*

do-install:
	@${MKDIR} ${PREFIX}/etc/mail
	@${INSTALL_PROGRAM} ${WRKSRC}/milter-greylist ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/greylist.conf.5 ${PREFIX}/man/man5
	@${INSTALL_MAN} ${WRKSRC}/milter-greylist.8 ${PREFIX}/man/man8
	@${INSTALL_DATA} ${WRKSRC}/greylist.conf \
			${PREFIX}/etc/mail/greylist.conf.sample

post-install:
	@${MKDIR} /var/milter-greylist
	@${CHOWN} smmsp /var/milter-greylist
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
.if !defined (NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/greylist.conf ${EXAMPLESDIR}
.endif
	@${TEST} -f /var/db/milter-greylist/greylist.db && ( \
		${ECHO} "***********************************************************"; \
		${ECHO} "***********************************************************"; \
		${ECHO} "**                                                       **"; \
		${ECHO} "**                      WARNING                          **"; \
		${ECHO} "**                                                       **"; \
		${ECHO} "** The default dump file location has changed.           **"; \
		${ECHO} "** Please move greylist.db from /var/db/milter-greylist/ **"; \
		${ECHO} "** to /var/milter-greylist/                              **"; \
		${ECHO} "**                                                       **"; \
		${ECHO} "***********************************************************"; \
		${ECHO} "***********************************************************"; \
	) || ${TRUE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
