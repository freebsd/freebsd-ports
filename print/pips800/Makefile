# New ports collection makefile for: pips for EPSON PM-800C
# Date created:        00/05/22
# Whom:                Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pips${PRTYPE}
PORTVERSION=	1.2
CATEGORIES=	print linux
MASTER_SITES?=	http://www.epkowa.on.arena.ne.jp/pips/data/800/
DISTNAME?=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.i386.tgz

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS+=	/compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_base \
		/compat/linux/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk \
		pstops:${PORTSDIR}/print/psutils-${PAPERSIZE}

ONLY_FOR_ARCHS= i386
NO_WRKSUBDIR=	yes
PLIST_SUB=	BASE_NAME=${BASE_NAME} PRTYPE=${PRTYPE}
MD5_FILE=	${.CURDIR}/distinfo

BASE_NAME=	pips${PRTYPE}
PAPERSIZE?=	a4

.include <bsd.port.pre.mk>
PRTYPE?=	800

do-build:
	${MV} ${WRKDIR}/filter${PRTYPE} ${WRKDIR}/filter${PRTYPE}.org
	${SED}	-e 's,/usr/local/EPKowa/PM${PRTYPE}C/gsconfig${PRTYPE},${PREFIX}/libexec/pips${PRTYPE}/gsconfig${PRTYPE},' \
		-e 's,/usr/bin/pips${PRTYPE},${PREFIX}/bin/pips${PRTYPE},' \
		-e 's,:/usr/local/bin$$,:${PREFIX}/bin,' \
		${WRKDIR}/filter${PRTYPE}.org > ${WRKDIR}/filter${PRTYPE}
	${SED}	-e 's,/usr/local/EPKowa/PM800C/gsconfig800,${PREFIX}/libexec/pips${PRTYPE}/gsconfig${PRTYPE},' \
		-e 's,/usr/local/bin/pips800,${PREFIX}/bin/pips${PRTYPE},' \
		-e 's,:/usr/local/bin$$,:${PREFIX}/bin,' \
		${FILESDIR}/filter.rev > ${WRKDIR}/filter${PRTYPE}.rev

do-install:
	${MKDIR} ${PREFIX}/libexec/${BASE_NAME}
	${INSTALL_SCRIPT} ${WRKDIR}/filter${PRTYPE} ${PREFIX}/libexec/${BASE_NAME}
	${INSTALL_SCRIPT} ${WRKDIR}/filter${PRTYPE}.rev ${PREFIX}/libexec/${BASE_NAME}
#	${INSTALL_SCRIPT} ${FILESDIR}/pips_filter ${PREFIX}/libexec/${BASE_NAME}
	${INSTALL_DATA} ${WRKSRC}/gsconfig${PRTYPE} ${PREFIX}/libexec/${BASE_NAME}
	chmod +x ${PREFIX}/libexec/${BASE_NAME}/gsconfig${PRTYPE}
	${INSTALL_DATA} ${WRKSRC}/libPrt${PRTYPE}.so /compat/linux/usr/lib/
	-/compat/linux/sbin/ldconfig
	${INSTALL_DATA} ${WRKSRC}/pips${PRTYPE} ${PREFIX}/bin
	${CHMOD} +x ${PREFIX}/bin/pips${PRTYPE}
.if !defined(NOPORTSDOCS)
	${MKDIR} ${PREFIX}/share/doc/${BASE_NAME}
	${INSTALL_DATA} ${WRKSRC}/readme${PRTYPE} ${PREFIX}/share/doc/${BASE_NAME}
.endif

# target for maintainer
_MAKE_COMMENT_DESCR:
.if ${PRTYPE} != 800
.for file in pkg-comment pkg-descr
.if ${PRTYPE} == 820_3300
	${SED}	-e 's/PM-800C/PM-820C PM-3300C/g' \
		-e 's/pm800c/pm820c_3300c/g' \
		-e 's/800/${PRTYPE}/g' \
		${MASTERDIR}/${file} > ${.CURDIR}/${file}
.else
	${SED}	-e 's/800/${PRTYPE}/g' ${MASTERDIR}/${file} \
		> ${.CURDIR}/${file}
.endif
.endfor
.endif

.include <bsd.port.post.mk>
