# New ports collection makefile for: netscape-linux-6
# Date created:			8 April 2000
# Whom:				sada@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	linux-netscape
PORTVERSION=	6.0
CATEGORIES=	www linux
MASTER_SITES=	ftp://ftp.netscape.com/pub/netscape6/english/${PORTVERSION}/unix/linux22/sea/ \
		ftp://ftp.cadvision.com/pub/linuxberg/files/ \
		ftp://ftp.proxad.net/mirrors/ftp.linuxberg.com/files/ \
		ftp://ftp.datacomm.ch/.3/linuxberg/files/ \
		ftp://ftp.inter-i.uni-mainz.de/pub/Software/windows9x/Netz/Browser/Netscape_Communicator_6_linux22_english/ \
		ftp://ftp.ptb.de/pub/WWW/Netscape/unix/ \
		ftp://ftp.darenet.dk/mirrors/mirror.linuxberg.com/files/ \
		ftp://ftp.info.univ-angers.fr/pub/linux/netscape6-english/ \
		ftp://ftp.chemo.tuniv.szczecin.pl/dsk4/www.linuxberg.com/files/ \
		ftp://ftp.uakom.sk/pub/linuxberg/files/ \
		ftp://ftp.dei.uc.pt/.disk2/linuxberg/files/ \
		ftp://ftp.is.co.za/packages/linuxberg/files/ \
		ftp://ftp.matrix.com.br/pub/linuxberg/files/ \
		ftp://ftp.duth.gr/pub/linuxberg/files/ \
		ftp://ftp.rndavia.ru/pub/linux/
DISTNAME=	netscape-i686-pc-linux-gnu-sea
DIST_SUBDIR=	netscape6/english/${PORTVERSION}

MAINTAINER=	trevor@FreeBSD.org

RUN_DEPENDS=	${LINUX_BASE}/lib/ld.so:${PORTSDIR}/emulators/linux_base \
		${LINUX_BASE}/usr/lib/libgtk-1.2.so.0.5.0:${PORTSDIR}/x11-toolkits/linux-gtk \
		${LINUX_BASE}/usr/lib/libjpeg.so.62.0.0:${PORTSDIR}/graphics/linux-jpeg

LINUX_BASE=	/compat/linux
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	i386
USE_XLIB=	yes
WRKSRC=	${WRKDIR}/netscape-installer/xpi

INSTALL_DIR=	${PREFIX}/lib/linux-netscape6
PLIST=		${WRKDIR}/pkg-plist
STARTUP_CMD=	netscape6

do-extract:
	${MKDIR} ${WRKSRC}
	@${TAR} xzf ${DISTDIR}/${DISTFILES} -C ${WRKDIR}
.for i in browser deflenus jre langenus mail psm spellchecker xpcom
	unzip -qo ${WRKSRC}/${i}.xpi -d ${WRKSRC}
.endfor
	${MV} ${WRKSRC}/psm ${WRKSRC}/bin
	${MV} ${WRKSRC}/jre-image-i386 ${WRKSRC}/bin/plugins/java2
	cd ${WRKSRC}/bin/plugins && ${LN} -s java2/plugin/i386/ns600/libjavaplugin_oji.so;
	${MV} ${WRKSRC}/../license.txt ${WRKSRC}
.if !defined(NOPORTDOCS)
	${MV} ${WRKSRC}/../README ${WRKSRC}
.endif

do-patch:
	${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/bin/chrome/user-skins.rdf ${WRKSRC}/bin/chrome/user-locales.rdf
	${CP} -p ${FILESDIR}/*rdf ${WRKSRC}/bin/chrome

do-configure:
	${SETENV} $DISPLAY="NONE" ${WRKSRC}/bin/netscape file:///dev/null
	${SED} -e "s;%%INSTALL_DIR%%;${INSTALL_DIR};g" \
	${FILESDIR}/start.sh >${WRKDIR}/${STARTUP_CMD}

pre-install:
	${ECHO} bin/${STARTUP_CMD} > ${PLIST}
	cd ${WRKSRC}/bin; for i in `find * \! -type d | sort`; do \
		${ECHO} lib/linux-netscape6/$${i} >> ${PLIST}; \
	done
	cd ${WRKSRC}/bin; \
	for i in `find -d * -type d`; do \
		${ECHO} @dirrm lib/linux-netscape6/$${i} >> ${PLIST}; \
	done
	${ECHO} @dirrm lib/linux-netscape6 >> ${PLIST}

do-install:
	${MKDIR} ${INSTALL_DIR}
	${CP} -Rp ${WRKSRC}/bin/* ${INSTALL_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP_CMD} ${PREFIX}/bin
	${CAT} ${WRKSRC}/license.txt

.include <bsd.port.mk>
