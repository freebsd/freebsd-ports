# New ports collection makefile for:	vbsfilter
# Date created:				10.Mar 2001
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	vbsfilter
PORTVERSION=	1.11
CATEGORIES=	mail
MASTER_SITES=	http://aeschi.ch.eu.org/milter/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.c
EXTRACT_ONLY=	# empty

MAINTAINER=	dinoex@FreeBSD.org

.if !defined(SENDMAIL_MILTER_IN_BASE)
BUILD_DEPENDS=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/sendmail
.endif

CTARGETS+=	vbsfilter-${PORTVERSION}
LIBS+=		${PTHREAD_LIBS}
CFLAGS+=	-Wall ${PTHREAD_CFLAGS:S=""==}
.if !defined(SENDMAIL_MILTER_IN_BASE)
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

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

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${_DISTDIR}vbsfilter-${PORTVERSION}.c ${WRKSRC}
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=" ${FILESDIR}/vbsfilter.sh \
		> ${WRKSRC}/vbsfilter.sh

.for i in ${CTARGETS}
${i}:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} ${LDFLAGS} -o ${i} ${i}.c ${LIBS} ${FLAGS}

.endfor

do-build:	${CTARGETS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vbsfilter-${PORTVERSION} \
		${PREFIX}/libexec/vbsfilter
	${INSTALL_SCRIPT} ${WRKSRC}/vbsfilter.sh \
		${PREFIX}/etc/rc.d/vbsfilter.sh.sample

.include <bsd.port.post.mk>
