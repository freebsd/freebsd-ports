# $FreeBSD$

PORTNAME=	raysfilter
PORTVERSION=	1.14
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=dinoex
DISTNAME=	rays-filter-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A configurable filter for Sendmail Milter

CTARGETS+=	rays-filter
CFLAGS+=	-Wall ${PTHREAD_CFLAGS:S=""==}
LIBS+=		${PTHREAD_LIBS}
ETCFILES=	header-list.conf mail-filter.conf string-list.conf
BINFILES=	mf-reset mf-start mf-stop mf-archive mf-analyze mf-memory
DOCSFILES=	rays-filter.html install.html configure.html operate.html \
		utilities.html GNU-public-licence.txt copyright.txt README

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if exists(${LOCALBASE}/include/libmilter/mfdef.h) \
|| defined(WITH_SENDMAIL_BASE)
LIBS+=		-lmilter
.else
LIBS+=		-lmilter -lsmutil
.endif

.if defined(SENDMAIL_WITH_SFIO)
LIBS+=		-lsfio
.endif

.for i in ${CTARGETS}
${i}:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} ${LDFLAGS} -o ${i} ${i}.c ${LIBS} ${FLAGS}

.endfor

do-build:	${CTARGETS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rays-filter \
		${STAGEDIR}${PREFIX}/libexec/rays-filter
	${INSTALL_SCRIPT} ${WRKSRC}/mail-filter \
		${STAGEDIR}${PREFIX}/etc/rc.d/raysfilter.sh.sample
.for i in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail-filter
.for i in ${ETCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/etc/mail-filter/${i}-dist
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
