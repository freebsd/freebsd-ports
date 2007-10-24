# New ports collection makefile for:	bsmtrace
# Date created:        13 March 2007
# Whom:                alm
#
# $FreeBSD$
#

PORTNAME=	bsmtrace
PORTVERSION=	1.1.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	csjp

MAINTAINER=	alm@FreeBSD.org
COMMENT=	BSM based intrusion detection system

SUB_FILES=	pkg-message
MAN1=		bsmtrace.1
MAN5=		bsmtrace.conf.5

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 602000
IGNORE=		release 6.2-RELEASE or later is required
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
MAKE_ENV+=	PCRE=1
.endif

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

.include <bsd.port.post.mk>
