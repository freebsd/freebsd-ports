# New ports collection makefile for: pips for EPSON PM-800C
# Date created:        00/05/22
# Whom:                Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pips${PRTYPE}
PORTVERSION?=	1.2
PORTREVISION=	1
CATEGORIES?=	print linux
MASTER_SITES?=	http://www.epkowa.on.arena.ne.jp/pips/data/${PRTYPE}/
DISTNAME?=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.i386.tgz

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS+=	/compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_base \
		/compat/linux/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk \
		pstops:${PORTSDIR}/print/psutils-${PAPERSIZE}

ONLY_FOR_ARCHS= i386
NO_WRKSUBDIR=	yes
PLIST_SUB=	BASE_NAME=${BASE_NAME} PRTYPE=${PRTYPE} LIB_DIR_FILE=usr/lib/${LIB_FILE} LIB_README=${LIB_README}
MD5_FILE=	${.CURDIR}/distinfo
.if (${PORTVERSION} == 1.2)
LIB_FILE=	libPrt${PRTYPE}.so
LIB_README=	"@comment Readme of the Lib for only 1.3 or later"
FILTER=		${FILESDIR}/filter.rev_1.2
.else
RUN_DEPENDS+=	/compat/linux/usr/lib/libpng.so.2:${PORTSDIR}/graphics/linux-png
.if defined(INTERNATIONAL_PRODUCTS)
LIB_FILE=	lib${PRTYPE:S/^-//}.so
LIB_README=	share/doc/${BASE_NAME}/lib${PRTYPE:S/^-//}.readme
PLIST=		${MASTERDIR}/pkg-plist.ip
RUN_DEPENDS+=	/compat/linux/usr/share/locale/ja_JP/LC_COLLATE:${PORTSDIR}/japanese/linux_locale \
		/compat/linux/usr/share/locale/ko/LC_COLLATE:${PORTSDIR}/korean/linux_locale
.else
LIB_FILE=	libpm${PRTYPE}c.so
LIB_README=	share/doc/${BASE_NAME}/libpm${PRTYPE}c.readme
.endif
FILTER=		${FILESDIR}/filter.rev
.endif
BASE_NAME=	pips${PRTYPE}
PAPERSIZE?=	a4
# for slave ports
COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr

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
		${FILTER} > ${WRKDIR}/filter${PRTYPE}.rev

do-install:
	${MKDIR} ${PREFIX}/libexec/${BASE_NAME}
	${INSTALL_SCRIPT} ${WRKDIR}/filter${PRTYPE} ${PREFIX}/libexec/${BASE_NAME}
	${INSTALL_SCRIPT} ${WRKDIR}/filter${PRTYPE}.rev ${PREFIX}/libexec/${BASE_NAME}
#	${INSTALL_SCRIPT} ${FILESDIR}/pips_filter ${PREFIX}/libexec/${BASE_NAME}
	${INSTALL_DATA} ${WRKSRC}/gsconfig${PRTYPE} ${PREFIX}/libexec/${BASE_NAME}
	chmod +x ${PREFIX}/libexec/${BASE_NAME}/gsconfig${PRTYPE}
	${INSTALL_DATA} ${WRKSRC}/${LIB_FILE} /compat/linux/usr/lib/
	-/compat/linux/sbin/ldconfig
	${INSTALL_DATA} ${WRKSRC}/pips${PRTYPE} ${PREFIX}/bin
	${CHMOD} +x ${PREFIX}/bin/pips${PRTYPE}
.if !defined(NOPORTSDOCS)
	${MKDIR} ${PREFIX}/share/doc/${BASE_NAME}
	${INSTALL_DATA} ${WRKSRC}/readme${PRTYPE} ${PREFIX}/share/doc/${BASE_NAME}
.if (${PORTVERSION} != 1.2)
	${INSTALL_DATA} ${WRKSRC}/${LIB_README:T} ${PREFIX}/${LIB_README}
.endif
.endif
.if defined(INTERNATIONAL_PRODUCTS)
	${MKDIR} ${PREFIX}/share/doc/${BASE_NAME}/pips_mo
	${INSTALL_DATA} ${WRKSRC}/pips_mo/* ${PREFIX}/share/doc/${BASE_NAME}/pips_mo
# zh zh_TW are not supported. en.gmo is not necessary.
.for lc in de es fr it ko nl pt
	${INSTALL_DATA} ${WRKSRC}/pips_mo/${lc}.gmo /compat/linux/usr/share/locale/${lc}/LC_MESSAGES/pips.mo
.endfor
	${INSTALL_DATA} ${WRKSRC}/pips_mo/ja.gmo /compat/linux/usr/share/locale/ja_JP/LC_MESSAGES/pips.mo
.endif

# a target for the maintainer
_MAKE_COMMENT_DESCR:
.if defined(INTERNATIONAL_PRODUCTS)
.if ${PRTYPE} != -sc880
.for file in pkg-comment pkg-descr
.if ${PRTYPE} == -sc680_777
	${SED}	-e 's,Stylus Color880,Stylus Color680/Stylus Color777,g' \
		-e 's/880/${PRTYPE:S/^-sc//}/g' \
		${.CURDIR}/../pips-sc880/${file} > ${.CURDIR}/${file}
.else
	${SED}	-e 's/880/${PRTYPE:S/^-sc//}/g' \
		${.CURDIR}/../pips-sc880/${file} > ${.CURDIR}/${file}
.endif
.endfor
.endif
.else # for defined(INTERNATIONAL_PRODUCTS)
.if ${PRTYPE} != 800
.for file in pkg-comment pkg-descr
.if ${PRTYPE} == 820_3300
	${SED}	-e 's/PM-800C/PM-820C PM-3300C/g' \
		-e 's/pm800c/pm820c_3300c/g' \
		-e 's/800/${PRTYPE}/g' \
		${MASTERDIR}/${file} > ${.CURDIR}/${file}
.elif ${PRTYPE} == 750_2000
	${SED}	-e 's/PM-800C/PM-750C PM-2000C/g' \
		-e 's/pm800c/pm750c_2000c/g' \
		-e 's/800/${PRTYPE}/g' \
		${MASTERDIR}/${file} > ${.CURDIR}/${file}
.else
	${SED}	-e 's/800/${PRTYPE}/g' ${MASTERDIR}/${file} \
		> ${.CURDIR}/${file}
.endif
.endfor
.endif
.endif # for defined(INTERNATIONAL_PRODUCTS)

.include <bsd.port.post.mk>
