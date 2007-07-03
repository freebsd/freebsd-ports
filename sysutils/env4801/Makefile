# Ports collection makefile for:  env4801
# Date created:			  Tue, Nov 24th, 2004
# Whom:				  Patrick M. Hausen (pmh@hausen.com)
#
# $FreeBSD$
#

PORTNAME=		env4801
PORTVERSION=		0.3
PORTREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://phk.freebsd.dk/soekris/env4801/
DISTFILES=		Makefile env4801.c
DIST_SUBDIR=		env4801

MAINTAINER=		pmh@hausen.com
COMMENT=		Output the voltages and temperatures of a Soekris Net4801 computer

ONLY_FOR_ARCHS=		i386
NO_WRKSUBDIR=		yes
EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}
RC_SCRIPTS_SUB=		PREFIX=${PREFIX}
MAKE_ARGS=		-DNOMAN

PLIST_FILES=		sbin/env4801 etc/rc.d/env4801.sh

OPTIONS=		STATIC "Build a statically linked executable" On

.include <bsd.port.pre.mk>

post-patch:
.ifdef(WITHOUT_STATIC)
	@${REINPLACE_CMD} -e '/-static/d' ${WRKSRC}/Makefile
.endif

post-extract:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/env4801.sh > ${WRKSRC}/env4801.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/env4801 ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/env4801.sh ${PREFIX}/etc/rc.d

post-install:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${PKGMESSAGE}

.include <bsd.port.post.mk>
