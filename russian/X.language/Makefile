# New ports collection makefile for: X.language
# Version required:     X11R6
# Date created:         31 Aug 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.16 1997/12/25 22:42:19 ache Exp $
#

DISTNAME=       x6rus-2.2.0-bin
PKGNAME=        ru-X11-3.3
CATEGORIES=     russian x11
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/misc/fonts/cyrillic/xwindows/
EXTRACT_SUFX=   .tgz

MAINTAINER=	ache@FreeBSD.ORG

RUN_DEPENDS=	${X11BASE}/bin/xinit:${PORTSDIR}/x11/XFree86

WRKSRC=         ${WRKDIR}/cyrillic
NO_BUILD=       YES
USE_X11=        YES

XLIB = ${X11BASE}/lib/X11

#Be careful to not delete embedded tab characters
do-install:
	-mv ${XLIB}/fonts/cyrillic ${XLIB}/fonts/cyrillic.old
	-mkdir -p ${XLIB}/fonts/cyrillic/100dpi
	-mkdir -p ${XLIB}/fonts/cyrillic/75dpi
	-mkdir -p ${XLIB}/fonts/cyrillic/misc
	cd ${WRKSRC}; \
	${INSTALL_DATA} xrus.info ${XLIB}/fonts/cyrillic; \
	for i in 100dpi 75dpi misc; do \
		${INSTALL_DATA} $$i/* ${XLIB}/fonts/cyrillic/$$i; \
	done
	if [ -f	/etc/XF86Config	]; then	\
		grep -q ${XLIB}/fonts/cyrillic/misc /etc/XF86Config || { \
			cp /etc/XF86Config /etc/XF86Config.old; \
			(echo "/^[ 	]*FontPath/i"; \
			 echo "    FontPath	\"${XLIB}/fonts/cyrillic/75dpi\""; \
			 echo "    FontPath	\"${XLIB}/fonts/cyrillic/100dpi\""; \
			 echo "    FontPath	\"${XLIB}/fonts/cyrillic/misc\""; \
			 echo "."; echo "w"; echo "q"; ) > /tmp/ed.$$$$; \
			ed - /etc/XF86Config < /tmp/ed.$$$$; \
			rm -f /tmp/ed.$$$$; \
		}; \
	fi
#       ${INSTALL_DATA} ${FILESDIR}/xmodmap ${XLIB}/xinit/.Xmodmap
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

.include <bsd.port.mk>
