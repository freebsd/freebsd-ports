# Ports collection makefile for:	logcheck
# Date created:		9 December 1999
# Whom:			Dan Langille <dan@freebsddiary.org>
#
# $FreeBSD$
#

PORTNAME=	logcheck
PORTVERSION=	1.1.1
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sentrytools

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Auditing tool for system logs on Unix boxes

# Install binaries and config files readable to root only
BINMODE=	700
SHAREMODE=	600

LOGCHECK_TMP?=	/var/run/logcheck
PLIST_SUB+=	LOGCHECK_TMP=${LOGCHECK_TMP}

CONFIG_FILES=	logcheck.hacking logcheck.ignore \
		logcheck.violations logcheck.violations.ignore
DOCS=		CREDITS INSTALL README README.how.to.interpret README.keywords

do-build:
	cd ${WRKSRC}/src && ${CC} ${CFLAGS} -o logtail logtail.c
	${REINPLACE_CMD} -e 's!/usr/local/bin/logtail!${PREFIX}/bin/logtail!' \
		-e 's!/usr/local/etc/tmp!${LOGCHECK_TMP}!' \
		-e 's!/usr/local/etc/logcheck!${PREFIX}/etc/logcheck!' \
		${WRKSRC}/systems/freebsd/logcheck.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/logtail ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/systems/freebsd/logcheck.sh ${PREFIX}/etc
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${CONFIG_FILES}
	@${INSTALL_DATA} ${WRKSRC}/systems/freebsd/${f} ${PREFIX}/etc/${f}.sample
.endfor
	${TEST} -d ${LOGCHECK_TMP} || ${MKDIR} -m 700 ${LOGCHECK_TMP}
	${CHOWN} root:wheel ${LOGCHECK_TMP}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
