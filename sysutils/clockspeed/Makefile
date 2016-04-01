# Created by: Mario S F Ferreira <lioux@linf.unb.br> et al.
# $FreeBSD$

PORTNAME=	clockspeed
PORTVERSION=	0.62
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/clockspeed/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Uses a hardware tick counter to compensate for deviant system clock

LIB_DEPENDS=	libtai.so:devel/libtai

ALL_TARGET=	it
INSTALL_TARGET=	setup check

MAN_FILES=	clockadd.1 clockspeed.1 clockview.1 sntpclock.1 \
		taiclock.1 taiclockd.1
BIN_FILES=	clockadd clockspeed clockview sntpclock taiclock taiclockd

PREFIX_FIX_FILES=	leapsecs_read.c INSTALL
CLOCKSPEED_RC_SCRIPT_SAMPLE=	${FILESDIR}/clockspeed.sh.sample
RC_SCRIPT_STARTUP_DIR=		${PREFIX}/etc/rc.d

OPTIONS_DEFINE=	DOCS

post-extract:
# get this port working under FreeBSD non-i386
	@${INSTALL} ${FILESDIR}/tryclock_gettime.c ${WRKSRC}
	@${ECHO} tryclock_gettime.c >> ${WRKSRC}/FILES
.for file in SYSDEPS TARGETS
	@${ECHO} hasclock_gettime.h >> ${WRKSRC}/${file}
.endfor

post-patch:
	@${SED} "s!/usr/local/!${PREFIX}!" ${CLOCKSPEED_RC_SCRIPT_SAMPLE} > \
		${WRKDIR}/${CLOCKSPEED_RC_SCRIPT_SAMPLE:T}
.for file in ${PREFIX_FIX_FILES}
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor

do-configure:
	@${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s -L${LOCALBASE}/lib > ${WRKSRC}/conf-ld
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home

post-build:
	${CP} ${FILESDIR}/leapsecs.dat ${WRKSRC}/leapsecs.dat

do-install:
.for i in ${BIN_FILES}
	${INSTALL} ${WRKSRC}/${i} ${STAGEDIR}/${PREFIX}/bin/
.endfor
.for i in ${MAN_FILES}
	${INSTALL} ${WRKSRC}/${i} ${STAGEDIR}/${PREFIX}/man/man1/
.endfor
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${STAGEDIR}/${PREFIX}/etc/clockspeed
	${INSTALL_DATA} ${WRKSRC}/leapsecs.dat ${STAGEDIR}/${ETCDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${CLOCKSPEED_RC_SCRIPT_SAMPLE:T} \
		${STAGEDIR}/${RC_SCRIPT_STARTUP_DIR}/${CLOCKSPEED_RC_SCRIPT_SAMPLE:T}

post-install:
	@${SED} s!/usr/local/!${PREFIX}/! ${PKGMESSAGE}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PKGMESSAGE} \
		${STAGEDIR}${DOCSDIR}/INSTALL-FreeBSD

.include <bsd.port.mk>
