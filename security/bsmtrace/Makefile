# Created by: alm
# $FreeBSD$

PORTNAME=	bsmtrace
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	csjp

MAINTAINER=	alm@FreeBSD.org
COMMENT=	BSM based intrusion detection system

SUB_FILES=	pkg-message
MAN1=		bsmtrace.1
MAN5=		bsmtrace.conf.5

MAKE_JOBS_UNSAFE=	yes

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.3:${PORTSDIR}/devel/pcre
MAKE_ENV+=	PCRE=1
.endif

NO_STAGE=	yes
pre-build:
	${REINPLACE_CMD} -e \
		's,/etc/bsmtrace.conf,${PREFIX}/etc/bsmtrace.conf,' \
		${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsmtrace ${PREFIX}/sbin
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/bsmtrace.conf ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/bsmtrace.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bsmtrace.conf.5 ${MAN5PREFIX}/man/man5

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
