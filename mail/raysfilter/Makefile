# New ports collection makefile for:	raysfilter
# Date created:				19.Dec 2001
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	raysfilter
PORTVERSION=	1.14
CATEGORIES=	mail
MASTER_SITES=	http://www.sendmail-filter.sbu.ac.uk/
DISTNAME=	rays-filter-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/sendmail

CTARGETS+=	rays-filter
CFLAGS+=	-Wall -I$(LOCALBASE)/include ${PTHREAD_CFLAGS:S=""==}
FLAGS+=		${PTHREAD_LIBS}
LDFLAGS+=	-L$(LOCALBASE)/lib
ETCFILES=	header-list.conf mail-filter.conf string-list.conf
BINFILES=	mf-reset mf-start mf-stop mf-archive mf-analyze mf-memory
DOCSFILES=	rays-filter.html install.html configure.html operate.html \
		utilities.html GNU-public-licence.txt copyright.txt README

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/libmilter/mfdef.h)
LIBS+=		-lmilter -lsm -lsmutil
.else
LIBS+=		-lmilter -lsmutil
.endif

.if defined(BATCH)
SENDMAIL_WITH_MILTER=	yes
.endif

.if defined(SENDMAIL_WITH_SFIO)
LIBS+=		-lsfio
.endif

.if ! defined(SENDMAIL_WITH_MILTER)
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} You must set variable SENDMAIL_WITH_MILTER to YES,
	@${ECHO_MSG} and rebuild sendmail in the ports
	@${FALSE}
.endif

.for i in ${CTARGETS}
${i}:
	cd ${WRKSRC} && \
	$(CC) $(CFLAGS) $(LDFLAGS) -o ${i} ${i}.c $(LIBS) $(FLAGS)

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
