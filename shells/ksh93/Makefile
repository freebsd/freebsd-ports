# New ports collection makefile for:   ksh93
# Date created:                2000-12-26
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$
#
# Make sure that your configuration DOES NOT set ANY gcc-related
# variables.  ksh93 will not compile if you set even the seemingly
# most unrelated variable related to gcc configuration.  This means
# especially any flag which attempts to set the cputype.  Setting the
# cputype does absolutely nothing except cause systems to fail in
# horrible ways.  For any modern processor, setting the cputype only
# serves to expose gcc bugs and does nothing to speed up any known
# program.  If you are really unconvinced, go ahead but do not
# complain to me about it.
#

PORTNAME=	ksh93
PORTVERSION=	${KSHVERSION:S/-//g}
PORTREVISION=	2
CATEGORIES=	shells
MASTER_SITES=	http://www.research.att.com/~gsf/download/tgz/
DISTFILES=	INIT.${KSHVERSION}.tgz ast-ksh.${KSHVERSION}.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official AT&T release of KornShell 93

OPTIONS=	STATIC	"Static linking" off

RESTRICTED=	Source recipient must acknowledge license

FETCH_ARGS=	-Rr
FETCH_ENV=	HTTP_AUTH='basic:*:I accept www.opensource.org/licenses/cpl:.'
MAKE_ENV=	CCFLAGS="${CFLAGS}"
NO_WRKSUBDIR=	yes

MAN1=		ksh93.1

KSHVERSION=	2011-02-08

.include <bsd.port.options.mk>

.if defined(WITH_STATIC)
MAKE_ENV+=	LDFLAGS+=-static
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/bin/package ${WRKSRC}/src/cmd/INIT/package.sh

do-build:
	@cd ${WRKSRC} && ${SETENV} -i ${MAKE_ENV} ${SH} bin/package flat make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ksh ${PREFIX}/bin/ksh93
	${INSTALL_MAN} ${WRKSRC}/man/man1/sh.1 ${MAN1PREFIX}/man/man1/ksh93.1
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/fun/ && ${INSTALL_SCRIPT} dirs popd pushd ${EXAMPLESDIR}/
.endif

post-install:
	@${ECHO} "Updating /etc/shells"
	@${SED} -i '' '\|${PREFIX}/bin/ksh93|d' /etc/shells
	@${ECHO} ${PREFIX}/bin/ksh93 >> /etc/shells

test: build
	@cd ${WRKSRC}/src/cmd/ksh93/tests && \
		${SETENV} SHELL=${WRKSRC}/bin/ksh ${WRKSRC}/bin/ksh shtests

.include <bsd.port.mk>
