# New ports collection makefile for:	punkbuster anti cheat server
# Date created:		29 Mar 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	punkbuster
PORTVERSION=	0.0.956
CATEGORIES=	net linux
MASTER_SITES=	http://www.evenbalance.com/downloads/
DISTNAME=	pbsv${PORTVERSION:E}
DIST_SUBDIR=	punkbuster

MAINTAINER=	lioux@FreeBSD.org

RUN_DEPENDS=	${LINUXBASE}${PUNKBUSTER_DIR}${PUNKBUSTER_DATA}:${PUNKBUSTER_DATA_PORT}

NO_PACKAGE=     the software terms do not allow non-standard\
		${PORTNAME} distributions

USE_LINUX_PREFIX=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_SUB=	PUNKBUSTER_DIR="${PUNKBUSTER_DIR:S/^\///}" \
		PUNKBUSTER_DOC_DIR="${PUNKBUSTER_DOC_DIR}"

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
SORT?=		/usr/bin/sort
STRIP_LINUX=	${LINUXBASE}/usr/bin/strip

PUNKBUSTER_DIR=	/usr/games/punkbuster/
PUNKBUSTER_PROGRAM=	pb
PUNKBUSTER_DATA_PORT=	${.CURDIR}/../punkbuster-data
PUNKBUSTER_DATA!=	cd ${PUNKBUSTER_DATA_PORT} && ${MAKE} -V PUNKBUSTER_DATA
PUNKBUSTER_DATA_DISTFILES!=	cd ${PUNKBUSTER_DATA_PORT} && ${MAKE} -V DISTFILES
PUNKBUSTER_DOC_DIR=	usr/doc/${PKGNAME}/

pre-everything:: pkgmessage-output

post-extract:
.for file in ${PUNKBUSTER_DATA_DISTFILES}
	@${RM} ${WRKSRC}/${file}
.endfor

post-patch:
.for extension in cfg htm ini pbq txt
	@${PERL} -pi -ne "s!\r\n!\n!" ${WRKSRC}/*.${extension}
.endfor
	@${PERL} -pi -ne "s!\r\n!\n!" ${WRKSRC}/README

install-parse-plist: generate-plist
	@${PERL} -e 'open(FHANDLER,"${TMPPLIST}");' \
		-e 'open(FDIR,">${WRKDIR}/dirs.sh.tmp");' \
		-e 'open(FFILES,">${WRKDIR}/files.sh");' \
		-e 'while (!eof(FHANDLER)) {' \
			-e 'chop($$file = <FHANDLER>);' \
			-e '$$dir = $$file_partial = $$file;' \
			-e '$$file_partial =~ s!^(${PUNKBUSTER_DIR:S/^\///}|${PUNKBUSTER_DOC_DIR})!!;' \
			-e 'print FDIR "${INSTALL_DIR}", \
				" ", "\"${PREFIX}/$$dir\"", \
				"\n" if $$dir =~ s!(^\@dirrm\s+)!!;' \
			-e 'print FFILES "${INSTALL_DATA}", \
				" ", "\"${WRKSRC}/$$file_partial\"", \
				" ", "\"${PREFIX}/$$file\" || true", \
				"\n" if ($$file !~ m!^\@!);' \
		-e '}' \
		-e 'close(FFILES);' \
		-e 'close(FDIR);' \
		-e 'close(FHANDLER);'

install-scripts:
	@${INSTALL_DIR} ${PREFIX}${PUNKBUSTER_DIR}
	@${SORT} ${WRKDIR}/dirs.sh.tmp > ${WRKDIR}/dirs.sh
	@${SH} ${WRKDIR}/dirs.sh
	@${SH} ${WRKDIR}/files.sh 2>/dev/true

pkgmessage-output:
	@${CAT} ${PKGMESSAGE}

do-install: install-parse-plist install-scripts pkgmessage-output
	@${CAT} ${PKGMESSAGE}

	@${INSTALL_DATA} ${WRKSRC}/pbsvhl.cfg \
		${PREFIX}${PUNKBUSTER_DIR}/pbsvhl.cfg.sample
.if !exists(${PREFIX}${PUNKBUSTER_DIR}/pbsvhl.cfg)
	@${INSTALL_DATA} ${WRKSRC}/pbsvhl.cfg ${PREFIX}${PUNKBUSTER_DIR}
.endif
# humm, can we strip or the program will complain that the checksum changed?
	@${STRIP_LINUX} ${PREFIX}${PUNKBUSTER_DIR}${PUNKBUSTER_PROGRAM}
	@${CHMOD} ${BINMODE} ${PREFIX}${PUNKBUSTER_DIR}${PUNKBUSTER_PROGRAM}

.include <bsd.port.mk>
