# New ports collection makefile for: pips for EPSON PM-800C
# Date created:        00/05/22
# Whom:                Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pips${PRTYPE}
PORTVERSION?=	1.3.1
#PORTREVISION=	1
CATEGORIES?=	print linux
.if defined(INTERNATIONAL_PRODUCTS)
.if ${PRTYPE} == -sc20s
MASTER_SITES?=	http://www.epkowa.on.arena.ne.jp/pips/data/sc20/
.elif ${PRTYPE} == -sc40s
MASTER_SITES?=	http://www.epkowa.on.arena.ne.jp/pips/data/sc40/
.elif ${PORTVERSION} == 2.0 || ${PORTVERSION} == 2.1
MASTER_SITES?=	http://www.epkowa.on.arena.ne.jp/pips/data/${PRTYPE:S/^-//}_${PORTVERSION:S/.//}/
.else
MASTER_SITES?=	http://www.epkowa.on.arena.ne.jp/pips/data/${PRTYPE:S/^-//}/
.endif
.elif ${PORTVERSION} == 2.0 || ${PORTVERSION} == 2.1
MASTER_SITES?=	http://www.epkowa.on.arena.ne.jp/pips/data/${PRTYPE}_${PORTVERSION:S/.//}/ \
		http://www.epkowa.on.arena.ne.jp/pips/data/${PRTYPE}/
.else
MASTER_SITES?=	http://www.epkowa.on.arena.ne.jp/pips/data/${PRTYPE}/
.endif
DISTNAME?=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.i386.tgz

MAINTAINER=	taoka@FreeBSD.org
COMMENT?=	Photo Image Print System for Linux --- EPSON PM-800C

RUN_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base \
		${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk \
		pstops:${PORTSDIR}/print/psutils-${PAPERSIZE} \
		${LINUXBASE}/usr/lib/libpng.so.2:${PORTSDIR}/graphics/linux-png10
.if ${PORTVERSION} == 2.0 || ${PORTVERSION} == 2.1
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libgnome.so.32:${PORTSDIR}/x11/linux-gnomelibs \
		${LINUXBASE}/usr/lib/libgdk_imlib.so.1:${PORTSDIR}/graphics/linux-imlib \
		${LINUXBASE}/usr/lib/libesd.so.0:${PORTSDIR}/audio/linux-esound \
		${LINUXBASE}/usr/lib/libaudiofile.so.0:${PORTSDIR}/audio/linux-libaudiofile
.endif

ONLY_FOR_ARCHS= i386
NO_WRKSUBDIR=	yes
PLIST_SUB=	BASE_NAME=${BASE_NAME} PRTYPE=${PRTYPE} LIB_DIR_FILE=usr/lib/${LIB_FILE} LIB_README=${LIB_README} ETC_RC_D=${ETC_RC_D}
MD5_FILE=	${.CURDIR}/distinfo

.include <bsd.port.pre.mk>
PRTYPE?=	800

.if defined(INTERNATIONAL_PRODUCTS)
LIB_FILE=	lib${PRTYPE:S/^-//}.so
PRT_MODEL=	${PRTYPE:U:S/^-//}
.else
.if ${PRTYPE} == 790
LIB_FILE=	libpm${PRTYPE}pt.so
PRT_MODEL=	PM${PRTYPE}PT
.elif ${PRTYPE} == "780cs"
LIB_FILE=	libpm${PRTYPE}.so
PRT_MODEL=	PM${PRTYPE:U}
.elif ${PRTYPE} == "820ug"
LIB_FILE=	libpm820cug.so
PRT_MODEL=	PM820CUG
.else
LIB_FILE=	libpm${PRTYPE}c.so
PRT_MODEL=	PM${PRTYPE}C
.endif
.endif
LIB_README=	share/doc/${BASE_NAME}/${LIB_FILE:S/.so$//}.readme
FILTER=		${FILESDIR}/filter.rev
BASE_NAME=	pips${PRTYPE}
PAPERSIZE?=	a4
# for slave ports
DESCR=		${.CURDIR}/pkg-descr
.if ${PORTVERSION} == 2.0 && !defined(INTERNATIONAL_PRODUCTS)
LANGS=		ja
PLIST=		${MASTERDIR}/pkg-plist20
.elif ${PORTVERSION} == 1.3
PLIST=		${MASTERDIR}/pkg-plist13
.elif ${PORTVERSION} == "1.3.1"
LANGS=		de es fr it ja ko nl pt zh zh_TW
#RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/local/cmex16m.pcf.gz:${PORTSDIR}/chinese/cmexfonts
PLIST=		${MASTERDIR}/pkg-plist131
.elif ${PORTVERSION} == 1.0
LANGS=		de es fr it ja ko nl pt zh zh_TW
#RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/local/cmex16m.pcf.gz:${PORTSDIR}/chinese/cmexfonts
PLIST=		${MASTERDIR}/pkg-plist10
.elif defined(INTERNATIONAL_PRODUCTS) || ${PORTVERSION} == 2.1
LANGS=		de es fr it ja ko nl pt zh zh_TW
#RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/local/cmex16m.pcf.gz:${PORTSDIR}/chinese/cmexfonts
PLIST=		${MASTERDIR}/pkg-plist21
.endif
# Unfortunately printing out by using ekpd is not supported on FreeBSD.
# So much difference between USB drivers of FreeBSD and Linux ?
.if defined(WITH_EKPD)
ETC_RC_D=	"etc/rc.d/ekpd.sh"
WITH_EKPD=	yes # redefine
.else
ETC_RC_D=	"@comment etc/rc.d/ekpd.sh: ekpd is not supported on FreeBSD"
.endif #defined(WITH_EKPD)

.if ! defined(WITH_EKPD)
.if ${PORTVERSION} == 2.0 || ${PORTVERSION} == 2.1
pre-everything::
	@${ECHO_MSG} "##############################################"
	@${ECHO_MSG} "You execute \"make install WITH_EKPD=yes\""
	@${ECHO_MSG} "to try to test ekpd."
	@${ECHO_MSG} "Maintainer tried to use ekpd but it could not work."
	@${ECHO_MSG} "##############################################"
.endif
.elif ${PORTVERSION} != 2.0 && ${PORTVERSION} != 2.1
pre-everything::
	@${ECHO_MSG} "##############################################"
	@${ECHO_MSG} "You can \"make\" with WITH_EKPD=yes"
	@${ECHO_MSG} "in the case with \$${PORTVERSION} = 2.0 or 2.1."
	@${ECHO_MSG} "##############################################"
	${FALSE}
.endif

do-build:
	${MV} ${WRKDIR}/filter${PRTYPE} ${WRKDIR}/filter${PRTYPE}.org
	${SED}	-e 's,^EKPSTM.*$$,EKPSTM=${PREFIX}/bin/ekpstm,' \
		-e 's,^LANGPATH.*$$,LANGPATH=${PREFIX}/etc/pips${PRTYPE}/lang,' \
		-e 's,^GSCONF.*$$,GSCONF=${PREFIX}/libexec/pips${PRTYPE}/gsconfig${PRTYPE},' \
		-e 's,^PIPS.*$$,PIPS=${PREFIX}/bin/pips${PRTYPE},' \
		-e 's,:/usr/local/bin$$,:${PREFIX}/bin,' \
		${WRKDIR}/filter${PRTYPE}.org > ${WRKDIR}/filter${PRTYPE}
	${SED}	-e 's,$$GSCONF | $$PIPS -ui C,TMP=/tmp/pips.$$$$;\
trap "rm -rf $$TMP; exit" 0 2 3 4 6 7 8 10 11 12 13 15;\
psselect -r > $$TMP;\
$${GSCONF} < $$TMP | $${PIPS} -ui C,' \
		-e 's,$${GSCONF} | $${PIPS} -ui C,TMP=/tmp/pips.$$$$;\
trap "rm -rf $$TMP; exit" 0 2 3 4 6 7 8 10 11 12 13 15;\
psselect -r > $$TMP;\
$${GSCONF} < $$TMP | $${PIPS} -ui C,' \
		${WRKDIR}/filter${PRTYPE} > ${WRKDIR}/filter${PRTYPE}.rev
.if ! defined(WITH_EKPD)
# Remake filter${PRTYPE}.rev
.if ${PORTVERSION} == 1.3
	${SED}	-e 's,^GSCONF.*$$,GSCONF=${PREFIX}/libexec/pips${PRTYPE}/gsconfig${PRTYPE},' \
		-e 's,^PIPS.*$$,PIPS=${PREFIX}/bin/pips${PRTYPE},' \
		-e 's,:/usr/local/bin$$,:${PREFIX}/bin,' \
		${FILESDIR}/filter13.rev > ${WRKDIR}/filter${PRTYPE}.rev
.else
	${SED}	-e 's,^GSCONF.*$$,GSCONF=${PREFIX}/libexec/pips${PRTYPE}/gsconfig${PRTYPE},' \
		-e 's,^PIPS.*$$,PIPS=${PREFIX}/bin/pips${PRTYPE},' \
		-e 's,:/usr/local/bin$$,:${PREFIX}/bin,' \
		${FILESDIR}/filter.rev > ${WRKDIR}/filter${PRTYPE}.rev
.endif
.endif #defined(WITH_EKPD)
.if ${PORTVERSION} == 2.0 || ${PORTVERSION} == 2.1
	${MV} ${WRKDIR}/ekpdrc ${WRKDIR}/ekpdrc.org
	${SED}	-e 's,/dev/usb/lp0,/dev/ulpt0,' \
		${WRKDIR}/ekpdrc.org > ${WRKDIR}/ekpdrc
.endif

post-build:
	${SED}	-e 's,%%BASE_NAME%%,${BASE_NAME},g' \
		-e 's,%%PRTYPE%%,${PRTYPE},g' \
		-e 's,%%PRT_MODEL%%,${PRT_MODEL},g' \
		-e 's,%%VERSION%%,${PORTVERSION},'g \
		-e 's,%%LINUXBASE%%,${LINUXBASE},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%WITH_EKPD%%,${WITH_EKPD},g' \
			${FILESDIR}/setup > ${WRKDIR}/setup.freebsd

do-install:
	${MKDIR} ${PREFIX}/libexec/${BASE_NAME}
	${INSTALL_SCRIPT} ${WRKDIR}/filter${PRTYPE} ${PREFIX}/libexec/${BASE_NAME}
	${INSTALL_SCRIPT} ${WRKDIR}/filter${PRTYPE}.rev ${PREFIX}/libexec/${BASE_NAME}
	${INSTALL_DATA} ${WRKSRC}/gsconfig${PRTYPE} ${PREFIX}/libexec/${BASE_NAME}
	${CHMOD} +x ${PREFIX}/libexec/${BASE_NAME}/gsconfig${PRTYPE}
	${INSTALL_DATA} ${WRKSRC}/${LIB_FILE} ${LINUXBASE}/usr/lib/
	-${LINUXBASE}/sbin/ldconfig
	${INSTALL_DATA} ${WRKSRC}/pips${PRTYPE} ${PREFIX}/bin
	${CHMOD} +x ${PREFIX}/bin/pips${PRTYPE}
	${RM} -f ${LINUXBASE}/etc/pipsrc
	${TOUCH} ${LINUXBASE}/etc/pipsrc
	${CHMOD} 666 ${LINUXBASE}/etc/pipsrc
	${INSTALL_SCRIPT} ${WRKDIR}/setup.freebsd ${PREFIX}/libexec/${BASE_NAME}/setup
	${MKDIR} ${PREFIX}/libexec/${BASE_NAME}/scripts
	${INSTALL_DATA} ${FILESDIR}/en.lc ${PREFIX}/libexec/${BASE_NAME}/scripts
	${INSTALL_DATA} ${FILESDIR}/ja.lc ${PREFIX}/libexec/${BASE_NAME}/scripts
.if ${PORTVERSION} == 2.0 || ${PORTVERSION} == 2.1
	${INSTALL_DATA} ${WRKSRC}/ekpnavi ${PREFIX}/bin
	${CHMOD} +x ${PREFIX}/bin/ekpnavi
	${INSTALL_DATA} ${WRKSRC}/ekpstm ${PREFIX}/bin
	${CHMOD} +x ${PREFIX}/bin/ekpstm
	${INSTALL_DATA} ${WRKSRC}/ekpd ${PREFIX}/libexec
	${CHMOD} +x ${PREFIX}/libexec/ekpd
	${INSTALL_DATA} ${WRKSRC}/ekpdrc ${LINUXBASE}/etc
.if defined(WITH_EKPD)
	${INSTALL_SCRIPT} ${FILESDIR}/ekpd.sh ${PREFIX}/etc/rc.d
.endif #defined(WITH_EKPD)
.endif
.if defined(LANGS)
.if ${PORTVERSION} == 2.0 || ${PORTVERSION} == 2.1
	${MKDIR} ${PREFIX}/share/doc/${BASE_NAME}/ekpnavi_mo
	${MKDIR} ${PREFIX}/share/doc/${BASE_NAME}/ekpstm_mo
	${INSTALL_DATA} ${WRKSRC}/ekpnavi_mo/* ${PREFIX}/share/doc/${BASE_NAME}/ekpnavi_mo
	${INSTALL_DATA} ${WRKSRC}/ekpstm_mo/* ${PREFIX}/share/doc/${BASE_NAME}/ekpstm_mo
.endif
	${MKDIR} ${PREFIX}/share/doc/${BASE_NAME}/pips_mo
	${INSTALL_DATA} ${WRKSRC}/pips_mo/* ${PREFIX}/share/doc/${BASE_NAME}/pips_mo
.if ${PORTVERSION} == 1.0
	${RM} ${PREFIX}/share/doc/${BASE_NAME}/pips_mo/en.gmo
.endif
.for lc in ${LANGS}
	if [ "${lc}" = "ja" ]; then \
		[ -f ${WRKSRC}/pips_mo/${lc}.gmo ] && \
		   ${MKDIR} ${LINUXBASE}/usr/share/locale/ja_JP/LC_MESSAGES; \
		[ -f ${WRKSRC}/ekpnavi_mo/${lc}.gmo ] && \
		   ${INSTALL_DATA} ${WRKSRC}/ekpnavi_mo/${lc}.gmo ${LINUXBASE}/usr/share/locale/ja_JP/LC_MESSAGES/ekpnavi.mo; \
		[ -f ${WRKSRC}/ekpstm_mo/${lc}.gmo ] && \
		   ${INSTALL_DATA} ${WRKSRC}/ekpstm_mo/${lc}.gmo ${LINUXBASE}/usr/share/locale/ja_JP/LC_MESSAGES/ekpstm.mo; \
		[ -f ${WRKSRC}/pips_mo/${lc}.gmo ] && \
		   ${INSTALL_DATA} ${WRKSRC}/pips_mo/${lc}.gmo ${LINUXBASE}/usr/share/locale/ja_JP/LC_MESSAGES/pips.mo; \
	else \
		[ -f ${WRKSRC}/pips_mo/${lc}.gmo ] && \
		   ${MKDIR} ${LINUXBASE}/usr/share/locale/${lc}/LC_MESSAGES; \
		[ -f ${WRKSRC}/ekpnavi_mo/${lc}.gmo ] && \
		   ${INSTALL_DATA} ${WRKSRC}/ekpnavi_mo/${lc}.gmo ${LINUXBASE}/usr/share/locale/${lc}/LC_MESSAGES/ekpnavi.mo; \
		[ -f ${WRKSRC}/ekpstm_mo/${lc}.gmo ] && \
		   ${INSTALL_DATA} ${WRKSRC}/ekpstm_mo/${lc}.gmo ${LINUXBASE}/usr/share/locale/${lc}/LC_MESSAGES/ekpstm.mo; \
		[ -f ${WRKSRC}/pips_mo/${lc}.gmo ] && \
		   ${INSTALL_DATA} ${WRKSRC}/pips_mo/${lc}.gmo ${LINUXBASE}/usr/share/locale/${lc}/LC_MESSAGES/pips.mo; \
	fi
.endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${BASE_NAME}
	${INSTALL_DATA} ${WRKSRC}/readme${PRTYPE} ${PREFIX}/share/doc/${BASE_NAME}
	${INSTALL_DATA} ${WRKSRC}/${LIB_README:T} ${PREFIX}/share/doc/${BASE_NAME}
.if ! ( ${PORTVERSION} == 1.3 || ( ${PORTVERSION} == 2.0 && !defined(INTERNATIONAL_PRODUCTS) ) )
	${INSTALL_DATA} ${FILESDIR}/readme_for_zh ${PREFIX}/share/doc/${BASE_NAME}
.endif
.endif

.if ${PORTVERSION} == 2.0 || ${PORTVERSION} == 2.1
.if defined(WITH_EKPD)
post-install:
	${SETENV} PKG_PREFIX=${PREFIX} \
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif #defined(WITH_EKPD)
.endif

# a target for the maintainer
_MAKE_DESCR:
.if defined(INTERNATIONAL_PRODUCTS)
.if ${PRTYPE} != -sc880 || ${PORTVERSION} != 1.0
.for file in pkg-descr
.if ${PRTYPE} == -sc680_777
	${SED}	-e 's,Stylus Color 880,Stylus Color 680/Stylus Color 777,g' \
		-e 's/880/${PRTYPE:S/^-sc//}/g' \
		${.CURDIR}/../pips-sc880/${file} > ${.CURDIR}/${file}
.elif ${PRTYPE} == -sc20s
	${SED}	-e 's,Stylus Color 880,Stylus SC20,g' \
		-e 's/880/${PRTYPE:S/^-sc//}/g' \
		${.CURDIR}/../pips-sc880/${file} > ${.CURDIR}/${file}
.elif ${PRTYPE} == -sc40s
	${SED}	-e 's,Stylus Color 880,Stylus SC40,g' \
		-e 's/880/${PRTYPE:S/^-sc//}/g' \
		${.CURDIR}/../pips-sc880/${file} > ${.CURDIR}/${file}
.elif ${PRTYPE} == -sp810_820
	${SED}	-e 's,Stylus Color 880,Stylus Photo 810/Stylus Photo 820,g' \
		-e 's/880/${PRTYPE:S/^-sp//}/g' \
		${.CURDIR}/../pips-sc880/${file} > ${.CURDIR}/${file}
.else
	${SED}	-e 's/880/${PRTYPE:S/^-sc//}/g' \
		${.CURDIR}/../pips-sc880/${file} > ${.CURDIR}/${file}
.endif
.endfor
.endif
.else # for defined(INTERNATIONAL_PRODUCTS)
.if ${PRTYPE} != 800
.for file in pkg-descr
.if ${PRTYPE} == "750_2000"
	${SED}	-e 's/PM-800C/PM-750C PM-2000C/g' \
		-e 's/pm800c/pm750c_2000c/g' \
		-e 's/800/${PRTYPE}/g' \
		${MASTERDIR}/${file} > ${.CURDIR}/${file}
.elif ${PRTYPE} == 790
	${SED}	-e 's/PM-800C/PM-790PT/g' \
		-e 's/pm800c/pm790pt/g' \
		-e 's/800/${PRTYPE}/g' \
		${MASTERDIR}/${file} > ${.CURDIR}/${file}
.elif ${PRTYPE} == "780cs"
	${SED}	-e 's/PM-800C/PM-780CS/g' \
		-e 's/pm800c/pm780cs/g' \
		-e 's/800/${PRTYPE}/g' \
		${MASTERDIR}/${file} > ${.CURDIR}/${file}
.elif ${PRTYPE} == "820ug"
	${SED}	-e 's/PM-800C/PM-820CUG/g' \
		-e 's/pm800c/pm820cug/g' \
		-e 's/800/${PRTYPE}/g' \
		${MASTERDIR}/${file} > ${.CURDIR}/${file}
.else
	${SED}	-e 's/800/${PRTYPE}/g' ${MASTERDIR}/${file} \
		> ${.CURDIR}/${file}
.endif
.endfor
.endif
.endif # for defined(INTERNATIONAL_PRODUCTS)
.if ${PORTVERSION} == 1.3
	${MV} ${.CURDIR}/pkg-descr  ${.CURDIR}/pkg-descr.org
	${SED} "/To run with Japanese/,//d" \
		${.CURDIR}/pkg-descr.org > ${.CURDIR}/pkg-descr
	printf "To run with Japanese messages, you have to execute as follows:\n\
  env LANG=ja_JP pips${PRTYPE} -la JP\n" >> ${.CURDIR}/pkg-descr
	${RM} ${.CURDIR}/pkg-descr.org
.elif ${PORTVERSION} == 2.0 && !defined(INTERNATIONAL_PRODUCTS)
	${MV} ${.CURDIR}/pkg-descr  ${.CURDIR}/pkg-descr.org
	${SED} "/To run with Japanese/,//d" \
		${.CURDIR}/pkg-descr.org > ${.CURDIR}/pkg-descr
	printf "To run with Japanese messages, you have to execute as follows:\n\
  env LANG=ja_JP pips${PRTYPE}\n" >> ${.CURDIR}/pkg-descr
	${RM} ${.CURDIR}/pkg-descr.org
.endif

.include <bsd.port.post.mk>
