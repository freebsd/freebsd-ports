# New ports collection makefile for:	amanda
# Date created:				28th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	amanda
PORTVERSION=	2.3.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cs.umd.edu/pub/amanda/old-versions/

MAINTAINER=	ports@FreeBSD.org

MAN8=		amadmin.8 amanda.8 amcheck.8 amcleanup.8 amdump.8 amflush.8 \
		amlabel.8 amrestore.8 amtape.8

LIBEXEC_BIN=	amandad calcsize driver dumper getconf planner reporter \
		runtar selfcheck sendbackup-dump sendbackup-gnutar sendsize \
		taper
SBIN_BIN=	amadmin amcheck amflush amlabel amrestore amtape

post-patch:
	@${LN} -sf config.h-freebsd2 ${WRKSRC}/config/config.h
	@${SED} -e 's:%%CC%%:${CC}:g' \
		-e 's:%%CFLAGS%%:${CFLAGS}:g' \
	        -e 's:%%INSTALL%%:${INSTALL}:g' \
	        -e 's:%%PREFIX%%:${PREFIX}:g' \
		${WRKSRC}/config/options.h-vanilla > ${WRKSRC}/config/options.h
.for file in amanda.8 amcleanup.8 amflush.8 amlabel.8
	@cd ${WRKSRC}/man/; ${MV} ${file} ${file}.in; \
		${SED} -e 's:%%PREFIX%%:${PREFIX}:g' ${file}.in > ${file}
.endfor

post-install:
.for file in ${LIBEXEC_BIN}
	@if [ -f ${PREFIX}/libexec/amanda/${file} ]; then \
		strip ${PREFIX}/libexec/amanda/${file}; \
	fi
.endfor
.for file in ${SBIN_BIN}
	@if [ -f ${PREFIX}/sbin/${file} ]; then \
		strip ${PREFIX}/sbin/${file}; \
	fi
.endfor
	@${MKDIR} ${PREFIX}/share/examples/amanda
	${INSTALL_DATA} ${WRKSRC}/example/* ${PREFIX}/share/examples/amanda
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
