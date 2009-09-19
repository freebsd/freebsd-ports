# New ports collection makefile for:		linux-opera
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}
PORTREVISION=	1
CATEGORIES=	www linux
MASTER_SITES=	ftp://ftp.opera.com/pub/opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		ftp://ftp.sunet.se/pub/www/clients/Opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		ftp://sunsite.cnlab-switch.ch/mirror/opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		ftp://ftp.ntua.gr/pub/www/Opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		http://mirrors.pmmf.hu/mirror/opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		ftp://ftp.task.gda.pl/pub/opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		ftp://ftp.planetmirror.com/pub/opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		http://gd.tuwien.ac.at/infosys/browsers/opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/opera/linux/${OPERA_VER:S/.//}/final/en/i386/&,}
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${OPERA_VER}.gcc4-bundled-qt4.i386

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A blazingly fast, full-featured, standards-compliant browser

WRKSRC=		${WRKDIR}/${DISTNAME:S/.gcc/-${OPERA_BUILD}.gcc/}
USE_BZIP2=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	aspell naslibs png xorglibs
ONLY_FOR_ARCHS=	i386 amd64

NO_BUILD=	yes

OPERA_VER=	10.00
OPERA_BUILD=	4585
DATADIR=	${PREFIX}/share/${UNIQUENAME}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}

MAN1=		linux-opera.1

post-extract:
	@${MV} ${WRKSRC}/usr/share/man/man1/opera.1 \
		${WRKSRC}/usr/share/man/man1/${UNIQUENAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%LINUXBASE%%|${LINUXBASE}|g' \
			${WRKSRC}/install.sh \
			${WRKSRC}/usr/share/opera/defaults/pluginpath.ini
	@${REINPLACE_CMD} -e 's|man1/opera.1|man1/${UNIQUENAME}.1|g' \
		${WRKSRC}/Manifest.md5
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@(cd ${WRKSRC} && ./install.sh \
			--prefix=${PREFIX} \
			--docdir=${DOCSDIR} \
			--sharedir=${DATADIR} \
			--exec_prefix=${DATADIR}/bin \
			--plugindir=${DATADIR}/plugins)

.include <bsd.port.mk>
