# New ports collection makefile for:	raysfilter
# Date created:				19.Dec 2001
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	raysfilter
PORTVERSION=	1.14
CATEGORIES=	mail
MASTER_SITES=	http://www.sendmail-filter.lsbu.ac.uk/
DISTNAME=	rays-filter-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A configurable filter for Sendmail

.if !defined(SENDMAIL_MILTER_IN_BASE)
.if defined(SENDMAIL_WITH_SHARED_MILTER)
LIB_DEPENDS+=	milter.3:${PORTSDIR}/mail/${SENDMAIL_MILTER_PORT}
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/${SENDMAIL_MILTER_PORT}
.endif
.endif

SENDMAIL_MILTER_PORT?=	sendmail
CTARGETS+=	rays-filter
CFLAGS+=	-Wall ${PTHREAD_CFLAGS:S=""==}
LIBS+=		${PTHREAD_LIBS}
.if !defined(SENDMAIL_MILTER_IN_BASE)
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif
ETCFILES=	header-list.conf mail-filter.conf string-list.conf
BINFILES=	mf-reset mf-start mf-stop mf-archive mf-analyze mf-memory
DOCSFILES=	rays-filter.html install.html configure.html operate.html \
		utilities.html GNU-public-licence.txt copyright.txt README

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/libmilter/mfdef.h) \
|| defined(SENDMAIL_MILTER_IN_BASE)
LIBS+=		-lmilter
.else
LIBS+=		-lmilter -lsmutil
.endif

.if defined(SENDMAIL_WITH_SFIO)
LIBS+=		-lsfio
.endif

.if defined(SENDMAIL_WITHOUT_MILTER)
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} You must unset variable SENDMAIL_WITHOUT_MILTER,
	@${ECHO_MSG} and rebuild sendmail in the ports
	@${FALSE}
.endif

.for i in ${CTARGETS}
${i}:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} ${LDFLAGS} -o ${i} ${i}.c ${LIBS} ${FLAGS}

.endfor

do-build:	${CTARGETS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rays-filter \
		${PREFIX}/libexec/rays-filter
	${INSTALL_SCRIPT} ${WRKSRC}/mail-filter \
		${PREFIX}/etc/rc.d/raysfilter.sh.sample
.for i in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/bin/
.endfor
	${MKDIR} ${PREFIX}/etc/mail-filter
.for i in ${ETCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/etc/mail-filter/${i}-dist
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
