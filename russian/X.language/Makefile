# New ports collection makefile for: X.language
# Version required:     X11R6
# Date created:         31 Aug 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1995/08/30 00:49:35 ache Exp $
#

PKGNAME=        russian-X11
CATEGORIES+=    x11

MAINTAINER=	ache@FreeBSD.ORG

EXEC_DEPENDS += ${X11BASE}/bin/xinit:${PORTSDIR}/x11/XFree86

NO_EXTRACT=     YES
NO_WRKSUBDIR=   YES
NO_CONFIGURE=   YES
NO_PATCH=       YES
NO_BUILD=       YES
USE_X11=        YES
PACKAGE_NOINSTALL= YES

XLIB = ${X11BASE}/lib/X11
INSTALL_DATA = ${INSTALL} -c -m 644 -o ${BINOWN} -g ${BINGRP}

fetch:
	@true

extract:
	@true

patch:
	@true

configure:
	@true

build:
	@true

install: depends
	if [ -d ${XLIB}/locale ] ; then \
		if [ ! -d ${XLIB}/locale/koi8-r ] ; then \
			mkdir ${XLIB}/locale/koi8-r; \
			chown ${BINOWN}.${BINGRP} ${XLIB}/locale/koi8-r; \
			chmod 755 ${XLIB}/locale/koi8-r; \
		fi; \
		if [ ! -f ${XLIB}/locale/koi8-r/XLC_LOCALE ] ; then \
			${INSTALL_DATA} ${FILESDIR}/koi8-r ${XLIB}/locale/koi8-r/XLC_LOCALE; \
		fi; \
		if [ ! -f ${XLIB}/locale/tbl_data/tabkoi8-r ] ; then \
			${INSTALL_DATA} ${FILESDIR}/tabkoi8-r ${XLIB}/locale/tbl_data; \
		fi; \
		grep -q KOI8-R ${XLIB}/locale/locale.alias || { \
			cp ${XLIB}/locale/locale.alias ${XLIB}/locale/locale.alias.bak; \
			grep -v -f ${FILESDIR}/replace_alias_list < ${XLIB}/locale/locale.alias.bak > ${XLIB}/locale/locale.alias; \
			cat ${FILESDIR}/locale_alias_list >> ${XLIB}/locale/locale.alias; \
		}; \
		grep -q KOI8-R ${XLIB}/locale/locale.dir || { \
			cp ${XLIB}/locale/locale.dir ${XLIB}/locale/locale.dir.bak; \
			cat ${FILESDIR}/locale_dir_list >> ${XLIB}/locale/locale.dir; \
		}; \
	fi
	if [ ! -d ${XLIB}/nls ] ; then \
		mkdir ${XLIB}/nls; \
		chown ${BINOWN}.${BINGRP} ${XLIB}/nls; \
		chmod 755 ${XLIB}/nls; \
	fi
	if [ ! -f ${XLIB}/nls/ru_SU.KOI8-R ] ; then \
		${INSTALL_DATA} ${FILESDIR}/nls_koi8-r ${XLIB}/nls/ru_SU.KOI8-R; \
	fi
	if [ ! -f ${XLIB}/nls/C ] ; then \
		${INSTALL_DATA} ${FILESDIR}/nls_C ${XLIB}/nls/C; \
	fi
	if [ ! -f ${XLIB}/nls/nls.dir ] ; then \
		dl=`wc -l < ${FILESDIR}/nls_dir_list`; \
		echo $$dl > ${XLIB}/nls/nls.dir; \
		cat ${FILESDIR}/nls_dir_list >> ${XLIB}/nls/nls.dir; \
		chown ${BINOWN}.${BINGRP} ${XLIB}/nls/nls.dir; \
		chmod 644 ${XLIB}/nls/nls.dir; \
	else \
		grep -q KOI8-R ${XLIB}/nls/nls.dir || { \
			cp ${XLIB}/nls/nls.dir ${XLIB}/nls/nls.dir.bak; \
			d_sub=`grep -f ${FILESDIR}/replace_nls_list < ${XLIB}/nls/nls.dir.bak | wc -l`; \
			d_cnt=`grep '^[1-9][0-9]*$$' ${XLIB}/nls/nls.dir.bak`; \
			d_add=`wc -l < ${FILESDIR}/nls_dir_list`; \
			d_new=`expr $$d_cnt + $$d_add - $$d_sub`; \
			grep -v -f ${FILESDIR}/replace_nls_list < ${XLIB}/nls/nls.dir.bak | \
				sed 's/^[1-9][0-9]*$$/'$$d_new/ > ${XLIB}/nls/nls.dir; \
			cat ${FILESDIR}/nls_dir_list >> ${XLIB}/nls/nls.dir; \
		}; \
	fi
	if [ ! -f ${XLIB}/nls/nls.alias ] ; then \
		al=`wc -l < ${FILESDIR}/nls_alias_list`; \
		echo $$al > ${XLIB}/nls/nls.alias; \
		cat ${FILESDIR}/nls_alias_list >> ${XLIB}/nls/nls.alias; \
		chown ${BINOWN}.${BINGRP} ${XLIB}/nls/nls.alias; \
		chmod 644 ${XLIB}/nls/nls.alias; \
	else \
		grep -q KOI8-R ${XLIB}/nls/nls.alias || { \
			a_cnt=`grep '^[1-9][0-9]*$$' ${XLIB}/nls/nls.alias`; \
			a_add=`wc -l < ${FILESDIR}/nls_alias_list`; \
			a_new=`expr $$a_cnt + $$a_add`; \
			cp ${XLIB}/nls/nls.alias ${XLIB}/nls/nls.alias.bak; \
			sed "s/^[1-9][0-9]*$$/$$a_new/;q" < ${XLIB}/nls/nls.alias.bak > ${XLIB}/nls/nls.alias; \
			cat ${FILESDIR}/nls_alias_list >> ${XLIB}/nls/nls.alias; \
		}; \
	fi
	@${MAKE} ${.MAKEFLAGS} fake-pkg

.include <bsd.port.mk>
