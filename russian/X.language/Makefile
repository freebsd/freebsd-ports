# New ports collection makefile for: X.language
# Version required:     X11R6
# Date created:         31 Aug 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.18 1998/07/29 16:11:22 ache Exp $
#

DISTNAME=       ru-X11-3.3
CATEGORIES=     russian x11
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/misc/fonts/cyrillic/xwindows/
DISTFILES=      x6rus-2.2.0-bin.tgz

.if defined(NON_FREE_FONTS)
DISTFILES += Type1.koi8-r.tgz
.else
DISTFILES += Type1.koi8-r.free.tgz
.endif

MAINTAINER=	ache@FreeBSD.ORG

RUN_DEPENDS=	${X11BASE}/bin/xinit:${PORTSDIR}/x11/XFree86

NO_WRKSUBDIR=   YES
NO_BUILD=       YES
USE_X11=        YES

PKGTMP = ${X11BASE}/.Xinstmp
XLIB = ${X11BASE}/lib/X11
CYRF = ${XLIB}/fonts/cyrillic
T1DIR = ${XLIB}/fonts/Type1/fonts.dir
T1SCALE = ${XLIB}/fonts/Type1/fonts.scale

#Be careful to not delete embedded tab characters
do-install:
	-if [ ! -d ${CYRF}.old ]; then \
		mv ${CYRF} ${CYRF}.old; \
	fi
	-mkdir -p ${CYRF}/100dpi
	-mkdir -p ${CYRF}/75dpi
	-mkdir -p ${CYRF}/misc
	cd ${WRKSRC}; \
	${INSTALL_DATA} *.pfb ${XLIB}/fonts/Type1
	for i in ${T1DIR} ${T1SCALE}; do \
	grep -q cokoi8n $$i || { \
		cp $$i $$i.bak; \
		d_cnt=`grep '^[1-9][0-9]*$$' $$i.bak`; \
		d_add=`wc -l < ${WRKSRC}/fonts.dir-scale.add`; \
		d_new=`expr $$d_cnt + $$d_add`; \
		sed 's/^[1-9][0-9]*$$/'$$d_new/ < $$i.bak > $$i; \
		cat ${WRKSRC}/fonts.dir-scale.add >> $$i; \
	}; \
	done
	cd ${WRKSRC}/cyrillic; \
	${INSTALL_DATA} xrus.info ${CYRF}; \
	for i in 100dpi 75dpi misc; do \
		${INSTALL_DATA} $$i/* ${CYRF}/$$i; \
	done
	if [ -f	/etc/XF86Config	]; then	\
		grep -q ${CYRF}/misc /etc/XF86Config || { \
			cp /etc/XF86Config /etc/XF86Config.old; \
			(echo "/^[ 	]*FontPath/i"; \
			 echo "    FontPath     \"${CYRF}/75dpi\""; \
			 echo "    FontPath     \"${CYRF}/100dpi\""; \
			 echo "    FontPath     \"${CYRF}/misc\""; \
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

pre-package:
	-mkdir -p ${PKGTMP}
	cd ${FILESDIR}; \
	$(CP) nls_dir_list nls_alias_list replace_nls_list ${PKGTMP}
	cd ${WRKSRC}; \
	$(CP) fonts.dir-scale.add ${PKGTMP}

post-package:
	${RM} -rf ${PKGTMP}

.include <bsd.port.mk>
