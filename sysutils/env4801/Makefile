# Created by: Patrick M. Hausen (pmh@hausen.com)
# $FreeBSD$

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
MK_MAN=			no

PLIST_FILES=		sbin/env4801 etc/rc.d/env4801.sh

SUB_FILES=	env4801.sh pkg-message

OPTIONS_DEFINE=	STATIC
OPTIONS_DEFAULT=	STATIC
STATIC_DESC=	Build a statically linked executable

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MSTATIC}
	@${REINPLACE_CMD} -e '/-static/d' ${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/env4801 ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/env4801.sh ${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.mk>
