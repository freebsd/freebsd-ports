# New ports collection makefile for: clockspeed
# Date created:		16 June 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	clockspeed
PORTVERSION=	0.62
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/clockspeed/ \
		ftp://ftp.task.gda.pl/mirror/mirror.qmail.org/koobera/pub/software/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Uses a hardware tick counter to compensate for deviant system clock

LIB_DEPENDS=	tai.1:${PORTSDIR}/devel/libtai

ALL_TARGET=	it
INSTALL_TARGET=	setup check

MAN1=		clockadd.1 clockspeed.1 clockview.1 sntpclock.1 \
		taiclock.1 taiclockd.1

PREFIX_FIX_FILES=	${WRKSRC}/leapsecs_read.c ${WRKSRC}/INSTALL
CLOCKSPEED_RC_SCRIPT_SAMPLE=	${FILESDIR}/clockspeed.sh.sample
RC_SCRIPT_STARTUP_DIR=		${PREFIX}/etc/rc.d

.include <bsd.port.pre.mk>

post-extract:
# get this port working under FreeBSD non-i386
	@${INSTALL} ${FILESDIR}/tryclock_gettime.c ${WRKSRC}
	@${ECHO} tryclock_gettime.c >> ${WRKSRC}/FILES
.for file in SYSDEPS TARGETS
	@${ECHO} hasclock_gettime.h >> ${WRKSRC}/${file}
.endfor

post-patch: real-post-patch

do-configure:
	@${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s -L${LOCALBASE}/lib > ${WRKSRC}/conf-ld
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home

post-build:
	@${CP} ${LOCALBASE}/etc/leapsecs.dat ${WRKSRC}/leapsecs.dat

post-install: real-post-install

.include <bsd.port.post.mk>

real-post-patch:
	@${SED} "s!/usr/local/!${PREFIX}!" ${CLOCKSPEED_RC_SCRIPT_SAMPLE} > \
		${WRKDIR}/${CLOCKSPEED_RC_SCRIPT_SAMPLE:T}
.for file in ${PREFIX_FIX_FILES}
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${file}
.endfor

real-post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/doc/clockspeed
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/clockspeed
	@${INSTALL_DATA} ${PKGMESSAGE} \
		${PREFIX}/share/doc/clockspeed/INSTALL-FreeBSD
.endif
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/etc/clockspeed
	@${INSTALL_DATA} ${WRKSRC}/leapsecs.dat ${PREFIX}/etc/clockspeed
	@${INSTALL_SCRIPT} ${WRKDIR}/${CLOCKSPEED_RC_SCRIPT_SAMPLE:T} \
		${RC_SCRIPT_STARTUP_DIR}/${CLOCKSPEED_RC_SCRIPT_SAMPLE:T}
	@${SED} s!/usr/local/!${PREFIX}/! ${PKGMESSAGE}
