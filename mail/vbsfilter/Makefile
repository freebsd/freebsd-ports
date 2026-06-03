PORTNAME=	vbsfilter
PORTVERSION=	1.15
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.dinoex.de/pub/approved/
EXTRACT_SUFX=	.c
EXTRACT_ONLY=	# empty

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Vbs-attachment filter for Sendmail Milter

LICENSE=	GPLv2

USE_RC_SUBR=	vbsfilter
PLIST_FILES=	libexec/vbsfilter

CTARGETS+=	vbsfilter-${PORTVERSION}
LIBS+=		-lpthread -lmilter
CFLAGS+=	-Wall

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/vbsfilter-${PORTVERSION}.c ${WRKSRC}

.for i in ${CTARGETS}
${i}:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} ${LDFLAGS} -o ${i} ${i}.c ${LIBS} ${FLAGS}

.endfor

do-build:	${CTARGETS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vbsfilter-${PORTVERSION} \
		${STAGEDIR}${PREFIX}/libexec/vbsfilter

.include <bsd.port.post.mk>
