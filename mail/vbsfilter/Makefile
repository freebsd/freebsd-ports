# New ports collection makefile for:	vbsfilter
# Date created:				10.Mar 2001
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	vbsfilter
PORTVERSION=	1.3
CATEGORIES=	mail
MASTER_SITES=	http://aeschi.ch.eu.org/milter/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.c
EXTRACT_ONLY=	# empty

MAINTAINER=	dirk.meyer@dinoex.sub.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/sendmail

NO_PACKAGE=	"only with sendmail from the ports"

CTARGETS+=	vbsfilter-1.3
CFLAGS+=	-Wall -I$(LOCALBASE)/include ${PTHREAD_CFLAGS}
FLAGS+=		${PTHREAD_LIBS}
LDFLAGS+=	-L$(LOCALBASE)/lib
LIBS+=		-lmilter -lsmutil
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

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${_DISTDIR}vbsfilter-1.3.c ${WRKSRC}
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=" ${FILESDIR}/vbsfilter.sh \
		> ${WRKSRC}/vbsfilter.sh

.for i in ${CTARGETS}
${i}:
	cd ${WRKSRC} && \
	$(CC) $(CFLAGS) $(LDFLAGS) -o ${i} ${i}.c $(LIBS) $(FLAGS)

.endfor

do-build:	${CTARGETS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vbsfilter-1.3 ${PREFIX}/libexec/vbsfilter
	${INSTALL_DATA} ${WRKSRC}/vbsfilter.sh \
		${PREFIX}/etc/rc.d/vbsfilter.sh.sample

.include <bsd.port.mk>
