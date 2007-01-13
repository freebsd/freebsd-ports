# New ports collection makefile for:	vbsfilter
# Date created:				10.Mar 2001
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	vbsfilter
PORTVERSION=	1.15
CATEGORIES=	mail
MASTER_SITES=	http://aeschi.ch.eu.org/milter/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.c
EXTRACT_ONLY=	# empty

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A vbs-attachment filter for Sendmail Milter

SUB_FILES=	vbsfilter.sh
PLIST_FILES=	libexec/vbsfilter etc/rc.d/vbsfilter.sh.sample

CTARGETS+=	vbsfilter-${PORTVERSION}
LIBS+=		${PTHREAD_LIBS}
LIBS+=		-lmilter
CFLAGS+=	-Wall ${PTHREAD_CFLAGS:S=""==}

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(SENDMAIL_WITH_SFIO)
LIBS+=		-lsfio
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${_DISTDIR}vbsfilter-${PORTVERSION}.c ${WRKSRC}

.for i in ${CTARGETS}
${i}:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} ${LDFLAGS} -o ${i} ${i}.c ${LIBS} ${FLAGS}

.endfor

do-build:	${CTARGETS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vbsfilter-${PORTVERSION} \
		${PREFIX}/libexec/vbsfilter
	${INSTALL_SCRIPT} ${WRKDIR}/vbsfilter.sh \
		${PREFIX}/etc/rc.d/vbsfilter.sh.sample

.include <bsd.port.post.mk>
